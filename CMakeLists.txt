cmake_minimum_required(VERSION 3.20)
project(data_structure)
add_compile_options(-fexec-charset=UTF-8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 自动递归编译所有子目录的.cpp文件
file(GLOB_RECURSE ALL_SOURCES "*.cpp" "**/*.cpp")

add_executable(data_structure main.cpp ${ALL_SOURCES}
        05-三元组类/花生采摘.cpp
        05-三元组类/稀疏矩阵（含加法乘法）.cpp
        "01-线性表/顺序表/01_Sequential List.cpp"
        01-线性表/顺序表/02_insert.cpp
        01-线性表/顺序表/03_delete.cpp
        01-线性表/顺序表/04_find.cpp
        06-二叉树/二叉树的前序创建.cpp
        06-二叉树/二叉树析构函数release.cpp
        06-二叉树/二叉树的深度.cpp
        06-二叉树/二叉树结点个数.cpp
        06-二叉树/二叉树一维数组输出.cpp
        06-二叉树/二叉树节点删除.cpp
        06-二叉树/二叉树中完全二叉树的判断.cpp
        06-二叉树/二叉树层序遍历.cpp
        06-二叉树/二叉树层序输入前序输出.cpp
        peactice/practice.cpp
        peactice/lianbiaofanzhuan.cpp
        "peactice/delete the repeat.cpp"
        "peactice/two sum.cpp"
        peactice/list.cpp)
