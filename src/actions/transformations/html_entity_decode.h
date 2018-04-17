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
#include <unordered_map>

#include "modsecurity/actions/action.h"
#include "src/actions/transformations/transformation.h"
#include "src/utils/string.h"

#ifndef SRC_ACTIONS_TRANSFORMATIONS_HTML_ENTITY_DECODE_H_
#define SRC_ACTIONS_TRANSFORMATIONS_HTML_ENTITY_DECODE_H_

#ifdef __cplusplus
namespace modsecurity {
class Transaction;

namespace actions {
namespace transformations {


class HtmlEntityDecode : public Transformation {
    /** @ingroup ModSecurity_RefManual */
    /**

    Description

    Group: Transformation

    \verbatim
    Decodes the characters encoded as HTML entities. The following variants are
    supported:

    - HH and HH; (where H is any hexadecimal number)
    - DDD and DDD; (where D is any decimal number)
    - &quotand"
    - &nbspand 
    - &ltand<
    - &gtand>

    This function always converts one HTML entity into one byte, possibly
    resulting in a loss of information (if the entity refers to a character
    that cannot be represented with the single byte). It is thus useful to
    uncover bytes that would otherwise not need to be encoded, but it cannot
    do anything meaningful with the characters from the range above 0xff.
    \endverbatim


    Details

    \verbatim
    \endverbatim

    */
 public:
    explicit HtmlEntityDecode(std::string action)
        : Transformation(action) { }

    std::string evaluate(std::string exp,
        Transaction *transaction) override;

    static int inplace(unsigned char *input, uint64_t input_len);
};


}  // namespace transformations
}  // namespace actions
}  // namespace modsecurity

#endif

#endif  // SRC_ACTIONS_TRANSFORMATIONS_HTML_ENTITY_DECODE_H_
