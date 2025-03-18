#pragma once

#include <functional>
#include <unordered_map>
#include <string>
#include <string_view>
#include <iostream>
#include <mutex>
#include <thread>
#include <uwebsockets/App.h>
#include "Module.hpp"

class WebSocketServerService final : public Module {
public:
    using MessageCallback = std::function<void(std::string_view message)>;
    using CloseCallback = std::function<void>;

    [[nodiscard]] std::string_view name() const override {
        return "WebSocketServerService";
    }

    void run() override {
        serverThread = std::thread([this] {
            std::cout << "Starting WebSocket server on port 9001..." << std::endl;

            uWS::App().ws<PerSocketData>("/*", {
                .open = [](auto* ws) {
                    std::cout << "Client connected" << std::endl;
                },
                .message = [this](auto* ws, const std::string_view message, uWS::OpCode) {
                    std::lock_guard lock(routesMutex);

                    auto json = nlohmann::json::parse(message);
                    if (!json.contains("route")) {
                        std::cerr << "No route specified" << std::endl;
                        return;
                    }

                    if (auto it = routes.find(json["route"]); it != routes.end()) {
                        it->second(message);
                    }
                },
                .close = [](auto*, const int code, const std::string_view message) {
                    std::cout << "Client disconnected: " << message << " (Code: " << code << ")" << std::endl;
                }
            }).listen(9001, [](const auto* listen_socket) {
                if (listen_socket) {
                    std::cout << "Listening..." << std::endl;
                }
            }).run();
        });


        serverThread.detach();
    }

    void stop() override {
        std::cout << "Stopping WebSocket server..." << std::endl;
        if (serverThread.joinable()) {
            serverThread.join();
        }
    }

    void registerHandler(const std::string& path, MessageCallback callback) {
        std::lock_guard lock(routesMutex);
        routes[path] = std::move(callback);
    }


private:
    struct PerSocketData {};

    std::unordered_map<std::string, MessageCallback> routes;
    std::mutex routesMutex;
    std::thread serverThread;
};