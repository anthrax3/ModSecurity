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

#ifndef SRC_ACTIONS_TRANSFORMATIONS_BASE64_DECODE_EXT_H_
#define SRC_ACTIONS_TRANSFORMATIONS_BASE64_DECODE_EXT_H_

#ifdef __cplusplus
namespace modsecurity {
class Transaction;

namespace actions {
namespace transformations {

class Base64DecodeExt : public Transformation {
    /** @ingroup ModSecurity_RefManual */
    /**

    Description

    Group: Transformation

    \verbatim
    Decodes a Base64-encoded string. Unlike base64Decode, this version uses a
    forgiving implementation, which ignores invalid characters.

    See blog post on Base64Decoding evasion issues on PHP sites -
    http://blog.spiderlabs.com/2010/04/impedance-mismatch-and-base64.html
    \endverbatim


    Details

    \verbatim
    \endverbatim

    */
 public:
    explicit Base64DecodeExt(std::string action) : Transformation(action) { }

    std::string evaluate(std::string exp,
        Transaction *transaction) override;
};

}  // namespace transformations
}  // namespace actions
}  // namespace modsecurity

#endif

#endif  // SRC_ACTIONS_TRANSFORMATIONS_BASE64_DECODE_EXT_H_
