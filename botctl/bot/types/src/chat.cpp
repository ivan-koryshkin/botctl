#include "chat.h"

#include <iostream>

namespace bot::types {

Chat::Chat(
    std::optional<string>           type,
    std::optional<string>           title,
    std::optional<string>           username,
    std::optional<string>           first_name,
    std::optional<string>           last_name,
    std::optional<BaseObject>       photo,
    std::optional<string>           bio,
    std::optional<bool>             has_private_forwards,
    std::optional<string>           description,
    std::optional<string>           invite_link,
    std::optional<BaseObject>       pinned_message,
    std::optional<BaseObject>       permissions,
    std::optional<int>              slow_mode_delay,
    std::optional<int>              message_auto_delete_time,
    std::optional<bool>             has_protected_content,
    std::optional<string>           sticker_set_name,
    std::optional<bool>             can_set_sticker_set,
    std::optional<int>              linked_chat_id,
    std::optional<BaseObject>       location
) : BaseObject(), 
    type(type),
    title(title),
    username(username),
    first_name(first_name),
    last_name(last_name),
    photo(photo),
    bio(bio),
    has_private_forwards(has_private_forwards),
    description(description),
    invite_link(invite_link),
    pinned_message(pinned_message),
    permissions(permissions),
    slow_mode_delay(slow_mode_delay),
    message_auto_delete_time(message_auto_delete_time),
    has_protected_content(has_protected_content),
    sticker_set_name(sticker_set_name),
    can_set_sticker_set(can_set_sticker_set),
    linked_chat_id(linked_chat_id),
    location(location)
{}

Chat::Chat(string& json) : BaseObject() {
    fromString(json);
}

Chat::Chat(Value const& document) : BaseObject() {
    fillObject(document);
}

void Chat::fillObject(Value const& document) {
    Parent::fillObject(document);
    type = getOptString(document, fields::TYPE);
    title = getOptString(document, TITLE);
    username = getOptString(document, USERNAME);
    first_name = getOptString(document, FIRSTNAME);
    last_name = getOptString(document, LASTNAME);
    /// \todo change to getting and fill nested object
    // photo = std::optional<BaseObject>{};
    bio = getOptString(document, BIO);
    has_private_forwards = getOptBool(document, HAS_PRIVATE_FORWARDS);
    description = getOptString(document, DESCRIPTION);
    invite_link = getOptString(document, INVITE_LINK);
    // pinned_message = std::optional<BaseObject>();
    // permissions = std::optional<BaseObject>();
    slow_mode_delay = getOptInt(document, SLOW_MODE_DELAY);
    message_auto_delete_time = getOptInt(document, MESSAGE_AUTO_DELETE_TIME);
    has_protected_content = getOptBool(document, HAS_PROTRCTED_CONTENT);
    sticker_set_name = getOptString(document, STICKER_SET_NAME);
    can_set_sticker_set = getOptBool(document, CAN_SET_STICKER_SET);
    linked_chat_id = getOptInt(document, LINKED_CHAT_ID);
    // location = std::optional<BaseObject>();
}

void Chat::fillDocument(Writer &writer) const {
    Parent::fillDocument(writer);
    if(type) {
        writer.Key(fields::TYPE);
        writer.String(type->c_str());
    }
    if(title)
    {
        writer.Key(fields::TITLE);
        writer.String(title->c_str());
    }
    if(username)
    {
        writer.Key(fields::USERNAME);
        writer.String(username->c_str());
    }
    if(first_name)
    {
        writer.Key(fields::FIRST_NAME);
        writer.String(first_name->c_str());
    }
    if(last_name)
    {
        writer.Key(fields::LAST_NAME);
        writer.String(last_name->c_str());
    }
    if(bio)
    {
        writer.Key(fields::BIO);
        writer.String(bio->c_str());
    }
    if(has_private_forwards)
    {
        writer.Key(HAS_PRIVATE_FORWARDS.c_str());
        writer.Bool(*has_private_forwards);
    }
    if(description)
    {
        writer.Key(DESCRIPTION.c_str());
        writer.String(description->c_str());
    }
    if(invite_link)
    {
        writer.Key(INVITE_LINK.c_str());
        writer.String(invite_link->c_str());
    }
    if(slow_mode_delay)
    {
        writer.Key(SLOW_MODE_DELAY.c_str());
        writer.Int(*slow_mode_delay);
    }
    if(message_auto_delete_time)
    {
        writer.Key(MESSAGE_AUTO_DELETE_TIME.c_str());
        writer.Int(*message_auto_delete_time);
    }
    if(has_protected_content)
    {
        writer.Key(HAS_PROTRCTED_CONTENT.c_str());
        writer.Bool(*has_protected_content);
    }
    if(sticker_set_name)
    {
        writer.Key(STICKER_SET_NAME.c_str());
        writer.String(sticker_set_name->c_str());
    }
    if(can_set_sticker_set)
    {
        writer.Key(CAN_SET_STICKER_SET.c_str());
        writer.Bool(*can_set_sticker_set);
    }
    if(linked_chat_id)
    {
        writer.Key(LINKED_CHAT_ID.c_str());
        writer.Int(*linked_chat_id);
    }
}

size_t Chat::hash() const {
    std::hash<string> hasher_str;
    std::vector<size_t> hash_vect = {
        Parent::hash()
    };
    if(type)
        hash_vect.push_back(hasher_str(*type));

    if(title)
        hash_vect.push_back(hasher_str(*title));

    if(username)
        hash_vect.push_back(hasher_str(*username));

    if(first_name)
        hash_vect.push_back(hasher_str(*first_name));

    if(last_name)
        hash_vect.push_back(hasher_str(*last_name));
    
    return Parent::combineHash(hash_vect);
}
}
