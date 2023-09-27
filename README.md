# LeetCode

LeetCode С++ solutions with VS Code.

<img width="50%" src="https://leetcard.jacoblin.cool/alexandr_morev?theme=wtf&ext=heatmap">

## Setup VS Code

Install c++ compiler and cmake in Ubuntu:
```bash
sudo apt-get install build-essential
sudo apt-get install cmake
```

Install VS Code extensions (Ctrl+P):
```
ext install ms-vscode.cpptools
ext install ms-vscode.cpptools-extension-pack
ext install ms-vscode.cpptools-themes

ext install ms-vscode.cmake-tools
ext install twxs.cmake
ext install matepek.vscode-catch2-test-adapter

ext install ms-python.python
ext install ms-python.vscode-pylance
```

## Generating a template for a task

Open project and run the following command in the VS Code terminal:

```bash
python3 gen_task.py "Some Problem"
```

Open the following files:

```bash
code solutions/some-problem/solution.hpp
code solutions/some-problem/test.cpp
```

After writing the solution to the problem and the tests, use the VS Code status bar to run the tests:
![plot](./res/status-bar.png)

Or use TestMate extension:
![plot](./res/test-mate.png)

## Auto-Format in VS Code

Install clang-format in Ubuntu:

```bash
sudo apt install clang-format
```

Install VS Code extensions:

```
ext install xaver.clang-format
ext install ms-python.black-formatter
```

Add the following lines to your .vscode/settings.json file:

```json
{
    "editor.formatOnSave": true,
    "C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools",
    "[python]": {
        "editor.defaultFormatter": "ms-python.black-formatter",
        "editor.formatOnSave": true
    },
    "python.formatting.provider": "none",
}
```
