/usr/bin/clear
/usr/bin/cc \
-std=c++17 -fno-diagnostics-color -Iinclude -Imain/src \
-Lbin -l:libglfw3.a -g main/src/*.cpp \
include/glad/*.c include/imgui/*.cpp -o bin/trajectoryBuilderMacArm &> build.log 