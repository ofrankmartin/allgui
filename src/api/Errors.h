#ifndef __ERRORS_H__
#define __ERRORS_H__

namespace AG {

typedef enum ReturnCode_s {
    RETURN_SUCCESS = 0x00,
    RETURN_ERROR_UNKNOWN = 0x01,
} ReturnCode;

}

#endif // __ERRORS_H__