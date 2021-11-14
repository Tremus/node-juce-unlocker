#include <napi.h>
#include "unlocker.h"
#include "crypto.h"


Napi::String unlock(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    const juce::String app_name       ((std::string)info[0].ToString());
    const juce::String user_email     ((std::string)info[1].ToString());
    const juce::String username       ((std::string)info[2].ToString());
    const juce::String machine_number ((std::string)info[3].ToString());
    const juce::String expiry_time    ((std::string)info[4].ToString());
    const juce::String privkey        ((std::string)info[5].ToString());

    std::string output = unlocker(app_name, user_email, username, machine_number, expiry_time, privkey);

    return Napi::String::New(env, output);
}

Napi::String encrypt(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    const juce::String message ((std::string)info[0].ToString());
    const juce::String privkey ((std::string)info[1].ToString());
    std::string output = encryptString(message, juce::RSAKey(privkey));

    return Napi::String::New(env, output);
}

Napi::String decrypt(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    const juce::String encryptedMessage ((std::string)info[0].ToString());
    const juce::String pubkey           ((std::string)info[1].ToString());
    std::string output = decryptString(encryptedMessage, juce::RSAKey(pubkey));

    return Napi::String::New(env, output);
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    // set a function
    exports.Set(
        Napi::String::New(env, "unlock"),
        Napi::Function::New(env, unlock)
    );
    exports.Set(
        Napi::String::New(env, "encrypt"),
        Napi::Function::New(env, encrypt)
    );
    exports.Set(
        Napi::String::New(env, "decrypt"),
        Napi::Function::New(env, decrypt)
    );

    return exports;
}

NODE_API_MODULE(greet, Init)
