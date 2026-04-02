
A web‑based clicker game where the core game logic is written in C++, compiled to WebAssembly, and controlled by a JavaScript front‑end


### Emscripten For windows

```powershell
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope Process


.\emsdk install latest
.\emsdk activate latest
.\emsdk_env.ps1 # Check which file is correct for Linux or Windows


```


### Toolchain

Enviorment File: `...\emsdk\emsdk_env.bat`

C Compiler: `...\emsdk\upstream\emscripten\emcc.bat`

C++ Compiler: `...\emsdk\upstream\emscripten\em++.bat`

ADD THIS PATH:
-DCMAKE_TOOLCHAIN_FILE= `.../emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake`

Start the WSL Session:
cd build
wsl


to start:
activate emscripten:
```powershell

cd C:\.....\emsdk
.\emsdk_env.ps1  #  .\emsdk_env.bat #.\emsdk_env.ps1 instead sinse i am using windows

```

Compiling project:
```
# Go back to reposatory
mkdir build
cd build
# Configure with Emscripten wrapper:
C:\...\emsdk\upstream\emscripten\emcmake.bat cmake ..
# Build the .wasm and .js files
cmake --build .
```

Can start a mini server with:
```
# Make sure CakeClicker.js, CakeClicker.wasm, index.html, and main.js are all inside
# Copy these if they are not in build yet
cp ..\web\index.html .
cp ..\web\main.js .
cp ..\web\style.css
# Then start server:
python -m http.server 8000
```


