#ifndef SOLID
#define SOLID

class Solid : public Object{
    public:
        Collider& getCollider(){ return col; }

    private:
        Collider col;
};

#endif
