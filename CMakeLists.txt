cmake_minimum_required(VERSION 4.3)
project(taskcli VERSION 1.0
                DESCRIPTION "a task manager only using cli programmed in c"
                LANGUAGES C)

set(source_dir "${PROJECT_SOURCE_DIR}/src/")
set(header_dir "${PROJECT_SOURCE_DIR}/header/")

file(GLOB source_files "${source_dir}/*.c")
file(GLOB header_files "${header_dir}/*.h")

add_executable(${PROJECT_NAME}  ${source_files} ${header_files})