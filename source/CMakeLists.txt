cmake_minimum_required(VERSION 3.5)
project(source)

set(SUBDIRS
    01_ThisPointer
    02_SendingThisPointer
    03_Casting
    04_Adapter
    05_VirtualFunction
    06_LSP
    07_Prototype
    08_TemplateMethod
    09_VirtualDestructor
    10_AbstractClass
    11_DIP
)
     
foreach(subdir ${SUBDIRS})
    add_subdirectory(${subdir})
endforeach(subdir ${SUBDIRS})
