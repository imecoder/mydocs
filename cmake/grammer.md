# CMake语法解析：掌握CMakeLists.txt的编写技巧
## 引言

CMake是一个强大的跨平台构建工具，用于管理和构建C/C++项目。在CMake中，项目的构建过程由CMakeLists.txt文件描述。

CMakeLists.txt文件采用CMake自己的脚本语言，其语法和编写技巧对于有效地构建和管理项目至关重要。本篇博客将深入学习CMakeLists.txt的语法和编写技巧，帮助读者更好地掌握CMake的强大功能。

## 1. 基本语法

### 注释

在CMake中，使用#符号表示注释。注释是对代码的解释说明，不会被CMake解析。例如：

```cmake
#这是一个注释
```

### 变量

在CMake中，使用set命令来定义变量。变量可以用于保存路径、编译选项等配置信息。例如：

```cmake
set(SRC_FILES main.cpp utils.cpp)
```

### 指令

CMake通过指令来完成不同的功能，例如添加目标、链接库等。指令以指令名(参数)的形式调用。例如：

```cmake
add_executable(my_target ${SRC_FILES})
```

## 2. 常用指令
<<<<<<< HEAD
#### cmake_minimum_required

```cmake
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)		#指定cmake最小版本
```

### project

```cmake
project(name LANGUAGES CXX)		#CXX代表C++
```

### set

```cmake
set(CMAKE_VERBOSE_MAKEFILE 1)	#设置编译过程编译命令显示
```

=======
>>>>>>> 8009ac0cdb348af953455cd1274566f0f4f0cc9a
### add_executable

add_executable指令用于添加可执行文件目标。它接受一个目标名和一组源文件。例如：

```cmake
add_executable(my_target main.cpp utils.cpp)
```
<<<<<<< HEAD

### add_library

add_library指令用于添加库目标。它可以创建静态库和共享库。例如：

```cmake
add_library(my_library STATIC utils.cpp)
```

| 参数   | 说明   |
| ------ | ------ |
| STATIC | 静态库 |
| SHARED | 动态库 |

### target_link_libraries

target_link_libraries指令用于链接目标与依赖的库。例如：

```cmake
target_link_libraries(my_target my_library)
```



### include_directories

include_directories指令用于指定头文件的搜索路径。例如：

```cmake
include_directories(${PROJECT_SOURCE_DIR}/include)
```

### set_target_properties

修改目标属性



```cmake
#修改动态库名称
set_target_properties(fun-shared PROPERTIES	OUTPUT_NAME "shared-fun")

#修改静态库名称
set_target_properties(fun-static PROPERTIES	OUTPUT_NAME "static-fun")

#保证编译的目标文件与生成位置无关
set_target_properties(fun-objs PROPERTIES POSITION_INDEPENDENT_CODE 1)
=======



### add_library

add_library指令用于添加库目标。它可以创建静态库和共享库。例如：

```cmake
add_library(my_library STATIC utils.cpp)
```



### target_link_libraries

target_link_libraries指令用于链接目标与依赖的库。例如：

```cmake
target_link_libraries(my_target my_library)
>>>>>>> 8009ac0cdb348af953455cd1274566f0f4f0cc9a
```



<<<<<<< HEAD
## 3. 条件判断

CMake支持条件判断，用于在不同条件下执行不同的构建逻辑。例如，可以根据操作系统类型或编译器类型执行不同的设置。条件判断使用if、else、elseif和endif来组织。例如：

```cmake
if(WIN32)
	# Windows平台的配置
elseif(UNIX)
    # Unix平台的配置
endif()
```

```txt
如果将逻辑变量设置为以下任意一种： 1 、 ON 、 YES 、 true 、 Y 或非零数，则逻辑变量为 true 。
如果将逻辑变量设置为以下任意一种： 0 、 OFF 、 NO 、 false 、 N 、 IGNORE、 NOTFOUND 、空字符串，或者以 -NOTFOUND 为后缀，则逻辑变量为 false。
```

### message

输出显示信息

```cmake
message(STATUS "Compile sources into a library?${USE_LIBRARY}")
```

### list

CMake中，列表是用分号分隔的字符串组。列表可以由 list 或 set 命令创建。例如， set(var a b c d e) 和 list(APPEND a b c d e) 都创建了列表 a;b;c;d;e

```cmake
#创建一个局部变量_sources，包括 Message.h 和 Message.cpp。
list(APPEND _sources Message.cpp Message.h)      
```



## 4. 循环

CMake支持循环指令，用于在CMakeLists.txt中执行迭代操作。例如，可以遍历一个文件列表并添加多个目标。CMake中的循环包括foreach和while等。例如：

```cmake
foreach(file IN LISTS SRC_FILES)
    add_executable(target_${file} ${file})
endforeach()
```



## 5. 函数和宏

CMake支持自定义函数和宏，用于封装重复使用的代码块。函数和宏的定义和调用类似。例如：

```cmake
function(print_hello)
    fun("Hello, CMake!")
endfunction()

print_hello()
```

## 6. 示例：一个简单的CMakeLists.txt文件

下面是一个简单的CMakeLists.txt文件的示例：

```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject)
set(SRC_FILES main.cpp utils.cpp)
add_executable(my_target ${SRC_FILES})
```

在上述示例中，我们指定了项目的最低CMake版本和项目名称。然后我们定义了一个变量SRC_FILES，存储了源文件列表。最后，我们使用add_executable指令创建了一个名为my_target的可执行文件目标，并将SRC_FILES中的源文件添加到该目标中。

## 7. 运行

可以单独创建一个目录，用于存在cmake中间文件。

```bash
mkdir build
cd build
cmake ..
```

## 总结

CMakeLists.txt是CMake项目的核心配置文件，其语法和编写技巧对于构建和管理项目至关重要。通过学习CMake的基本语法、常用指令、条件判断、循环和自定义函数、宏等，可以更好地掌握CMake的强大功能。


=======
### include_directories

include_directories指令用于指定头文件的搜索路径。例如：

```cmake
include_directories(${PROJECT_SOURCE_DIR}/include)
```



## 3. 条件判断

CMake支持条件判断，用于在不同条件下执行不同的构建逻辑。例如，可以根据操作系统类型或编译器类型执行不同的设置。条件判断使用if、else、elseif和endif来组织。例如：

```cmake
if(WIN32)
	# Windows平台的配置
elseif(UNIX)
    # Unix平台的配置
endif()
```



## 4. 循环

CMake支持循环指令，用于在CMakeLists.txt中执行迭代操作。例如，可以遍历一个文件列表并添加多个目标。CMake中的循环包括foreach和while等。例如：

```cmake
foreach(file IN LISTS SRC_FILES)
    add_executable(target_${file} ${file})
endforeach()
```



## 5. 函数和宏

CMake支持自定义函数和宏，用于封装重复使用的代码块。函数和宏的定义和调用类似。例如：

```cmake
function(print_hello)
    message("Hello, CMake!")
endfunction()
>>>>>>> 8009ac0cdb348af953455cd1274566f0f4f0cc9a

print_hello()
```

## 示例：一个简单的CMakeLists.txt文件

下面是一个简单的CMakeLists.txt文件的示例：

```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject)
set(SRC_FILES main.cpp utils.cpp)
add_executable(my_target ${SRC_FILES})
```

在上述示例中，我们指定了项目的最低CMake版本和项目名称。然后我们定义了一个变量SRC_FILES，存储了源文件列表。最后，我们使用add_executable指令创建了一个名为my_target的可执行文件目标，并将SRC_FILES中的源文件添加到该目标中。

## 总结

CMakeLists.txt是CMake项目的核心配置文件，其语法和编写技巧对于构建和管理项目至关重要。通过学习CMake的基本语法、常用指令、条件判断、循环和自定义函数、宏等，可以更好地掌握CMake的强大功能。