#ifndef SUIT_H
#define SUIT_H


class Suit
{
    public:
        Suit(suit);
        virtual ~Suit();
        Suit(const Suit& other);
        Suit& operator=(const Suit& other);
    protected:
    private:
};

#endif // SUIT_H
