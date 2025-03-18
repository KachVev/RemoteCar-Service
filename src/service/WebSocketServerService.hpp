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
    using MessageCallback = std::function<void(void* ws, std::string_view message)>;

    [[nodiscard]] std::string_view name() const override {
        return "WebSocketServerService";
    }

    void run() override {
        serverThread = std::thread([this]() {
            std::cout << "Starting WebSocket server on port 9001..." << std::endl;

            uWS::App().ws<PerSocketData>("/*", {
                .open = [](auto* ws) {
                    std::cout << "Client connected" << std::endl;
                },
                .message = [this](auto* ws, const std::string_view message, uWS::OpCode) {
                    std::lock_guard lock(routesMutex);
                    for (const auto& [path, callback] : routes) {
                        if (message.starts_with(path)) {
                            callback(ws, message);
                            return;
                        }
                    }
                    std::cout << "No handler found for message: " << message << std::endl;
                },
                .close = [](auto* ws, const int code, const std::string_view message) {
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