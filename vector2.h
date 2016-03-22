class Vector2{
    public:
        Vector2 operator+(Vector2 &v);
        Vector2 operator+(double d);

        Vector2 operator-(Vector2 &v);
        Vector2 operator-(double d);

        Vector2 operator*(Vector2 &v);
        Vector2 operator*(double d);

        Vector2 operator/(Vector2 &v);
        Vector2 operator/(double d);
    
        double x;
        double y;
        double z;
};
