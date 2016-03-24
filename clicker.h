class Clicker{
    public:
        Clicker();
        virtual void onClick() = 0;
        bool isIn(int mx, int my);
    private:
        int x;
        int y;
        int w;
        int h;
};
