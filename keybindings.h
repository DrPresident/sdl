#define A 
#define B 
#define C 
#define D 
#define E 
#define F 
#define G 
#define H 
#define I 
#define J 
#define K 
#define L 
#define M 
#define N 
#define O 
#define P 
#define Q 
#define R 
#define S 
#define T 
#define U 
#define V
#define W
#define X
#define Y
#define Z

#define ONE
#define TWO
#define THREE
#define FOUR
#define FIVE
#define SIX
#define SEVEN
#define EIGHT
#define NINE

#define TAB
#define LEFT_SHIFT
#define RIGHT_SHIFT
#define LEFT_CTRL
#define RIGHT_CTRL
#define LEFT_ALT
#define RIGHT_ALT
#define SPACEBAR
#define HYPHEN
#define LEFT_ARROW
#define RIGHT_ARROW
#define UP_ARROW
#define DOWN_ARROW
#define PG_UP
#define PG_DOWN
#define INSERT
#define DELETE
#define HOME
#define END
#define FORWARD_SLASH
#define BACK_SLASH
#define APOSTROPHE
#define SEMI_COLON
#define COMMA
#define PERIOD
#define TILDE
#define ESCAPE
#define OPEN_BRACE
#define CLOSED_BRACE

class KeyBinding{
    public:
        KeyBinding(const char* key);
        KeyBinding(int key);
    private:

        const char* key;
}
