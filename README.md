# CarRemote-server (Remote Driving)

## Project Description

**CarRemotePoligon** is a system for remotely controlling RC cars over the internet. The project allows users to rent cars, control them in real-time, and receive live video streams from their cameras.

## Project Goals

Develop a server for:
- Managing car connections and control.
- Streaming video from cars to the client.
- Sending control commands from the client to the car.
- Handling the rental system for cars.
- Monitoring battery charge levels.

## System Logic

### **User Flow**
1. **Authentication & Registration**
   - The user sends a request to register/log in via the client (mobile app, website, etc.).
   - The server retrieves and displays the user's profile information.

2. **Car Rental**
   - After authentication, the user sees a list of available cars that:  
     - Are not currently rented.  
     - Have a battery charge above 10%.  
   - After completing the rental process (payment, verification), the server assigns the car to the user.
   - The video stream from the car starts.
   - The server receives control commands (forward, backward, turn) from the client and sends them to the car.

### **Admin-Level Operations**
- Handles car connections and retrieves battery status.
- Adds available cars to the rental pool.
- Processes battery charge updates (each car checks its charge level every 10 minutes and sends updates via WebSockets).

## TODO List

### **Core Features**
- [ ] Implement user authentication and profile management.
- [x] Develop the car rental system.
- [ ] Establish WebSocket communication for real-time control.
- [ ] Implement live video streaming from cars.
- [ ] Design an admin panel for car management(Return data to client for display).

### **Hardware Integration**
- [ ] Connect ESP32 to control cars.
- [ ] Implement battery level monitoring.
- [ ] Develop a charging information system.

## Project Status

🚧 **The project is currently in development.** Source code is provided without binary files.

## Tech Stack

- **Server**: C++ (Raspberry Pi/Arduino)
- **Client**: Web/Mobile Application
- **Communication**: ESP32, WebSockets
- **Video Streaming**: Direct camera stream from cars
