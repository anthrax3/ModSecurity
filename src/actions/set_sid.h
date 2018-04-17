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
#include <utility>
#include <memory>

#include "modsecurity/actions/action.h"
#include "src/run_time_string.h"

#ifndef SRC_ACTIONS_SET_SID_H_
#define SRC_ACTIONS_SET_SID_H_

class Transaction;

namespace modsecurity {
class Transaction;
namespace actions {


class SetSID : public Action {
    /** @ingroup ModSecurity_RefManual */
    /**

    Description

    Group: Non-disruptive

    \verbatim
    Special-purpose action that initializes the SESSION collection using the
    session token provided as parameter.

    Note: After the initialization takes place, the variable SESSION will be
    available for use in the subsequent rules. This action understands
    application namespaces (configured using SecWebAppId), and will use one if
    it is configured.

    Setsid takes an individual variable, not a collection. Variables within an
    action, such as setsid, use the format [collection].[variable] .
    \endverbatim


    Example

    \verbatim
    # Initialise session variables using the session cookie value 
    = SecRule REQUEST_COOKIES:PHPSESSID !^$ "nolog,pass,id:138,setsid:%{REQUEST_COOKIES.PHPSESSID}"
    \endverbatim


    Details

    \verbatim
    \endverbatim

    */
 public:
    explicit SetSID(std::string _action)
        : Action(_action) { }

    explicit SetSID(std::unique_ptr<RunTimeString> z)
        : Action("setsid", RunTimeOnlyIfMatchKind),
            m_string(std::move(z)) { }

    bool evaluate(Rule *rule, Transaction *transaction) override;
    bool init(std::string *error) override;

 private:
    std::unique_ptr<RunTimeString> m_string;
};


}  // namespace actions
}  // namespace modsecurity

#endif  // SRC_ACTIONS_SET_SID_H_
