/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */

#include <string>

#include "modsecurity/actions/action.h"
#include "src/actions/transformations/transformation.h"

#ifndef SRC_ACTIONS_TRANSFORMATIONS_JS_DECODE_H_
#define SRC_ACTIONS_TRANSFORMATIONS_JS_DECODE_H_

#ifdef __cplusplus
namespace modsecurity {
class Transaction;

namespace actions {
namespace transformations {

class JsDecode : public Transformation {
    /** @ingroup ModSecurity_RefManual */
    /**

    Description

    Group: Transformation

    \verbatim
    Decodes JavaScript escape sequences. If a \uHHHH code is in the range of
    FF01-FF5E (the full width ASCII codes), then the higher byte is used to
    detect and adjust the lower byte. Otherwise, only the lower byte will be
    used and the higher byte zeroed (leading to possible loss of information).
    \endverbatim


    Details

    \verbatim
    \endverbatim

    */
 public:
    explicit JsDecode(std::string action)
        : Transformation(action) { }

    std::string evaluate(std::string exp,
        Transaction *transaction) override;
    static int inplace(unsigned char *input, uint64_t input_len);
};

}  // namespace transformations
}  // namespace actions
}  // namespace modsecurity

#endif

#endif  // SRC_ACTIONS_TRANSFORMATIONS_JS_DECODE_H_
