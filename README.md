# wip

I want to track with vcs so I am putting here. No point in trying to build. Infancy stage. Look at readme raw code if you wan't to follow the project.

<!---

# yekate

vulkan renderer.

Tested on win32 w/ clang and on unix-like with winemaker.

I am going to make a vidjya game with this engine.

## Compiling

You need to have vulkan 1.3 and the `VULKAN_SDK` env variable set up.

### Windows 

```
mkdir out
./build.bat
```
Uses clang. Write your own for other compilers. Scroll down to learn how.

### Linux / mac

I don't maintain this anymore since my wsl does not have vk 1.3.
You'd beed wine dev tools to do it. Thats what the shell script uses.

Until I get me a linux and god forbid a mac, I can't make back ends. Feel free to make them yourself. Once the platform layer receives more structure, you can try mirroring the respective backends.

```
mkdir out
./build.sh
```

### Writing your own

If you want to compile yourself, here is all the theory you need.

- Source files        : `code/entry/main.cpp`
- Include directories : `code/`
- compiler flags      : `-nostdlib -lkernel32 -luser32 -lgdi32 -vulkan-1`

Look for equivalents for your platform / compiler.
```

I also pass `-g` so I can have debug symbols. You don't need it unless you are developing.

## For contributors

### Contributing

Open an issue for anything.

Check `STYLE.md` to get started

### Project Structure

- `code/`        All of the source code
- `data/`        fonts, images, res

**`code/`**

- `entry/`       Main application entry point. Game will go here.
- `base/`        Common functions. Needs `os/` for crt equivalent functions. Can work without `os/` if stdlib is provided. stdlib is not provided.
- `os/`          contains os code.
- `draw/`        high level drawing layer
- `render/`      gpu api layer
- `gpu/`         shader code
- `third_party/` libraries that I like to use. Embedded inside.
- `scratch/`     temporary test code
- `gen/`         Files generated by the metaprogrammer go here.
- `meta/`        Entry point for the metaprogrammer. Doesn't need to be built unless you are developing.

-->