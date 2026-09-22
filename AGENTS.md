# 项目协作规则

## 题目文件

- 用户发送一道新的 HJ 题目时，为该题创建或更新独立的源文件。
- 文件名必须以题号开头，例如 `hj1_last_word.cpp`、`hj4_string_split.cpp`。
- 将题目内容整理成清晰的中文注释放在源文件最前面，至少包含：题号、题目名称、知识点、描述、输入描述、输出描述和全部样例。
- 样例应放在描述内容的前面，明确标注输入和输出，并保留题目中的关键限制条件。
- 整理新题目时，只添加题目描述、样例和一个空的 `main` 函数，不主动编写解题代码。
- 新建题目文件后，应直接创建对应的 CMake 可执行目标。

## CMake

- 项目统一使用 C++17。
- 每道题使用独立的 CMake 可执行目标，目标名与源文件名保持一致，例如：

  ```cmake
  add_executable(hj4_string_split src/hj4_string_split.cpp)
  ```

- 每个题目文件都应包含一个可编译的空 `main` 函数，因此创建文件时就加入对应的可执行目标。
- 新增目标时同步配置：
  - `target_compile_features(... PRIVATE cxx_std_17)`
  - `CXX_EXTENSIONS OFF`
  - MSVC 下的 `/utf-8`
- 修改、重命名或删除题目文件时，同步更新 `CMakeLists.txt` 中的目标名称和源文件路径。

## VS Code 运行

- VS Code 的运行和调试应使用 CMake Tools 生成的目标，不使用 C++ 扩展默认的 `cl.exe` 活动文件任务。
- 保持 `.vscode/settings.json` 使用 `ms-vscode.cmake-tools` 作为 C/C++ 配置提供程序。
- 保持 `.vscode/launch.json` 使用 `${command:cmake.launchTargetPath}` 作为运行程序路径。
- 用户运行某道题前，应在 CMake Tools 中选择对应的题目目标，再使用运行或调试功能。

## 检查原则

- 用户询问“是否正确”时，只检查当前文件，不擅自修改，除非用户要求修改。
- 检查时重点关注编译错误、输入输出格式、边界条件和题目要求是否一致。
- 不要覆盖用户已有的代码和改动。
