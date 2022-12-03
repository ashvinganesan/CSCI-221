#ifndef _COMPARE_H_
#define _COMPARE_H_
namespace Mynamespace {
template <typename String>
int comp(const String& a, const String& b) {
    if(sizeof(a) == sizeof(b)) {
        return 0;
    }
    if(sizeof(a) < sizeof(b)) {
        return -1;
    }
    return 1;
}
}
#endif // _COMPARE_H_
