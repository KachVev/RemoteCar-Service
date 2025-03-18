#pragma once
#include <functional>
#include <unordered_map>
#include <string_view>
#include <utility>


class WebSocketServerService final : public Module {
public:
    using MessageCallback = std::function<void(void* ws, std::string_view message)>;

    [[nodiscard]] std::string_view name() const override {
        return "WebSocketServerService";
    }

    void run() override {
        std::cout << "Starting websocket server..." << std::endl;

        for (const auto &path: routes | std::views::keys) {
            std::cout << "Registered handler for " << path << std::endl;
        }
    }

    void stop() override {}

    void registerHandler(const std::string& path, MessageCallback callback) {
        routes[path] = std::move(callback);

        std::cout << "Registered handler for " << path << std::endl;
    }
private:
    std::unordered_map<std::string, MessageCallback> routes;
};