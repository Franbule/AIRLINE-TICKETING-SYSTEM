#ifndef TEMP_H
#define TEMP_H


class temp
{
    public:
        temp();
        virtual ~temp();

        string Getname() { return name; }
        void Setname(string val) { name = val; }

    protected:

    private:
        string name;
};

#endif // TEMP_H
