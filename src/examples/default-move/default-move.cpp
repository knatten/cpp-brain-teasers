#include <iostream>

struct BaseClass1
{
    BaseClass1() = default;
    BaseClass1(const BaseClass1 &) { std::cout << "BaseClass1 copy\n"; }
    BaseClass1(BaseClass1 &&) { std::cout << "BaseClass1 move\n"; }
};

struct BaseClass2
{
    BaseClass2() = default;
    BaseClass2(const BaseClass2 &) { std::cout << "BaseClass2 copy\n"; }
    BaseClass2(BaseClass2 &&) { std::cout << "BaseClass2 move\n"; }
};

struct MemberClass1
{
    MemberClass1() = default;
    MemberClass1(const MemberClass1 &) { std::cout << "MemberClass1 copy\n"; }
    MemberClass1(MemberClass1 &&) { std::cout << "MemberClass1 move\n"; }
};

struct MemberClass2
{
    MemberClass2() = default;
    MemberClass2(const MemberClass2 &) { std::cout << "MemberClass2 copy\n"; }
    MemberClass2(MemberClass2 &&) { std::cout << "MemberClass2 move\n"; }
};

struct Class : public BaseClass1, public BaseClass2
{
    Class() = default;

    // START: Class-move
    Class(Class &&other) :
       BaseClass1{std::move(other)},
       BaseClass2{std::move(other)},
       /* ... */
       member1_{std::move(other).member1_},
       member2_{std::move(other).member2_}
       /* ... */
       {}
    // END: Class-move

    MemberClass1 member1_;
    MemberClass2 member2_;
};

struct Member
{
    Member() = default;
    Member(const Member &) { std::cout << "Member copy\n"; }
    Member(Member &&) { std::cout << "Member move\n"; }
};

struct WillItMove
{
    WillItMove() = default;

    // START: WillItMove-move
    WillItMove(WillItMove && other) :
         constMember_{std::move(other).constMember_}{}
    // END: WillItMove-move

    const Member constMember_{};
};


int main()
{
    Class c;
    Class c2(std::move(c));

    std::cout << "\n";

    WillItMove w;
    WillItMove w2(std::move(w));
}
