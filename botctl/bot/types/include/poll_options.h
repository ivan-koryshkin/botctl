#pragma once
#include "base_object.h"
#include "fields.h"

namespace bot::types {

class PollOption : public BaseObject {

public:
    string text;
    int voter_count;
    
    PollOption() : BaseObject() {}
    PollOption(string&);
    PollOption(const Value&);
    PollOption(string text, int voter_count);
    virtual ~PollOption() {}

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(rapidjson::Value const& document);
};

}