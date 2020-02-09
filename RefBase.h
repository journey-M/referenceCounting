#ifndef RS_REF_BASE_H
#define RS_REF_BASE_H


// ---------------------------------------------------------------------------

template <class T>
class LightRefBase
{
public:
    inline LightRefBase() : mCount(0) { }
    inline void incStrong(__attribute__((unused)) const void* id) const {
        __sync_fetch_and_add(&mCount, 1);
    }
    inline void decStrong(__attribute__((unused)) const void* id) const {
        if (__sync_fetch_and_sub(&mCount, 1) == 1) {
            delete static_cast<const T*>(this);
        }
    }
    //! DEBUGGING ONLY: Get current strong ref count.
    inline int32_t getStrongCount() const {
        return mCount;
    }

    typedef LightRefBase<T> basetype;

protected:
    inline ~LightRefBase() { }

private:

private:
    mutable volatile int32_t mCount;
};


#endif // RS_REF_BASE_H
