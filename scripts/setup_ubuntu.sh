#!/bin/bash
# =============================================================================
# Sim-Architecture-Lab Environment Setup Script (Ubuntu/WSL)
# Run: chmod +x scripts/setup_ubuntu.sh && ./scripts/setup_ubuntu.sh
# =============================================================================

set -e

echo "🔧 Updating package list..."
sudo apt update

echo "🔧 Installing build tools..."
sudo apt install -y build-essential cmake git

echo "🔧 Installing Raylib dependencies..."
sudo apt install -y \
    libgl1-mesa-dev \
    libx11-dev \
    libxcursor-dev \
    libxrandr-dev \
    libxinerama-dev \
    libxi-dev \
    libasound2-dev

echo ""
echo "✅ Setup complete!"
echo ""
cmake --version
g++ --version | head -1
