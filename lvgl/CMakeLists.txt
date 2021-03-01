cmake_minimum_required(VERSION 3.5)
project(Ui C)

SET(CROSS_COMPILE 1)
set(CMAKE_SYSTEM_NAME Linux)

# add_executable(main main.c mouse_cursor_icon.c ${SOURCES} ${INCLUDES})

#引入所有编译用到的源码目录
include_directories(
    lv_port_linux_frame_buffer/lv_drivers
    lv_port_linux_frame_buffer/lv_examples
    lv_port_linux_frame_buffer/lvgl
    lv_port_linux_frame_buffer/lv_drivers/display
    lv_port_linux_frame_buffer/lv_drivers/indev
    lv_port_linux_frame_buffer/lv_examples/assets
    lv_port_linux_frame_buffer/lv_examples/src/lv_demo_benchmark
    lv_port_linux_frame_buffer/lv_examples/src/lv_demo_keypad_encoder
    lv_port_linux_frame_buffer/lv_examples/src/lv_demo_printer
    lv_port_linux_frame_buffer/lv_examples/src/lv_demo_stress
    lv_port_linux_frame_buffer/lv_examples/src/lv_demo_widgets
    lv_port_linux_frame_buffer/lv_examples/src/lv_ex_get_started
    lv_port_linux_frame_buffer/lv_examples/src/lv_ex_style
    lv_port_linux_frame_buffer/lvgl/porting
    lv_port_linux_frame_buffer/lvgl/src/lv_core
    lv_port_linux_frame_buffer/lvgl/src/lv_draw
    lv_port_linux_frame_buffer/lvgl/src/lv_font
    lv_port_linux_frame_buffer/lvgl/src/lv_gpu
    lv_port_linux_frame_buffer/lvgl/src/lv_hal
    lv_port_linux_frame_buffer/lvgl/src/lv_misc
    lv_port_linux_frame_buffer/lvgl/src/lv_themes
    lv_port_linux_frame_buffer/lvgl/src/lv_widgets
    lv_port_linux_frame_buffer/lvgl/tests/lv_test_core
    lv_port_linux_frame_buffer/lvgl/tests/lv_test_objx
    lv_port_linux_frame_buffer/
    ./
)

#通过源码目录 引入所有源文件 形成文件变量
aux_source_directory(lv_port_linux_frame_buffer/lv_drivers LV_drivers)
aux_source_directory(lv_port_linux_frame_buffer/lv_examples LV_examples)
aux_source_directory(lv_port_linux_frame_buffer/lvgl LVgl)
aux_source_directory(lv_port_linux_frame_buffer/lv_drivers/display DISPLAY)
aux_source_directory(lv_port_linux_frame_buffer/lv_drivers/indev INDEV)
aux_source_directory(lv_port_linux_frame_buffer/lv_examples/assets ASSETS)
aux_source_directory(lv_port_linux_frame_buffer/lv_examples/src/lv_demo_benchmark BENCHMARK)
aux_source_directory(lv_port_linux_frame_buffer/lv_examples/src/lv_demo_keypad_encoder ENCODER)
aux_source_directory(lv_port_linux_frame_buffer/lv_examples/src/lv_demo_printer PRINTER)
aux_source_directory(lv_port_linux_frame_buffer/lv_examples/src/lv_demo_stress STRESS)
aux_source_directory(lv_port_linux_frame_buffer/lv_examples/src/lv_demo_widgets WIDGET)
aux_source_directory(lv_port_linux_frame_buffer/lv_examples/src/lv_ex_get_started STARTED)
aux_source_directory(lv_port_linux_frame_buffer/lv_examples/src/lv_ex_style STYLE)
aux_source_directory(lv_port_linux_frame_buffer/lvgl/porting PORTING)
aux_source_directory(lv_port_linux_frame_buffer/lvgl/src/lv_core CORE)
aux_source_directory(lv_port_linux_frame_buffer/lvgl/src/lv_draw DRAW)
aux_source_directory(lv_port_linux_frame_buffer/lvgl/src/lv_font FONT)
aux_source_directory(lv_port_linux_frame_buffer/lvgl/src/lv_gpu GPU)
aux_source_directory(lv_port_linux_frame_buffer/lvgl/src/lv_hal HAL)
aux_source_directory(lv_port_linux_frame_buffer/lvgl/src/lv_misc MISC)
aux_source_directory(lv_port_linux_frame_buffer/lvgl/src/lv_themes THEMES)
aux_source_directory(lv_port_linux_frame_buffer/lvgl/src/lv_widgets WIDGETS)
aux_source_directory(lv_port_linux_frame_buffer/lvgl/tests/lv_test_core TEST_CORE)
aux_source_directory(lv_port_linux_frame_buffer/lvgl/tests/lv_test_objx TEST_OBJX)
aux_source_directory(lv_port_linux_frame_buffer/lvgl LVgl)
aux_source_directory(lv_port_linux_frame_buffer/./ CUR)

#引入所有要编译的源文件
add_executable(Ui
    ${LV_drivers}
    ${LV_examples}
    ${LVgl}
    ${DISPLAY}
    ${INDEV}
    ${ASSETS}
    ${BENCHMARK}
    ${ENCODER}
    ${PRINTER}
    ${STRESS}
    ${WIDGET}
    ${STARTED}
    ${STYLE}
    ${PORTING}
    ${CORE}
    ${DRAW}
    ${FONT}
    ${GPU}
    ${HAL}
    ${MISC}
    ${THEMES}
    ${WIDGETS}
    ${TEST_CORE}
    ${TEST_OBJX}
    ${CUR}

)
