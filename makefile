debug: anim.cpp camera.cpp instance.cpp object.cpp screen.cpp sfx.cpp sprite.cpp anim.h camera.h collider.h controls.h instance.h object.h screen.h sfx.h sprite.h
	g++ -g -w *.cpp  -lSDL2 -lSDL2_mixer -lSDL2_image -o debug

test: debug
	./debug
