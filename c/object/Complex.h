class Complex
{
public:
    Complex();
    ~Complex();
    Complex(int real,int imag);
    void Display()const;

    friend Complex operator+(const Complex& one,const Complex& other);

private:
    int real_;
    int imag_;
};
