debug: anim.cpp camera.cpp hero.cpp instance.cpp object.cpp screen.cpp sfx.cpp sprite.cpp anim.h camera.h collider.h controls.h hero.h instance.h object.h screen.h sfx.h sprite.h visible.h
	g++ -g *.cpp -lSDL -lSDL_image -lSDL_mixer -o debug

test: anim.cpp camera.cpp hero.cpp instance.cpp object.cpp screen.cpp sfx.cpp sprite.cpp anim.h camera.h collider.h controls.h hero.h instance.h object.h screen.h sfx.h sprite.h visible.h
	g++ -g *.cpp -lSDL -lSDL_image -lSDL_mixer -o debug
	./debug