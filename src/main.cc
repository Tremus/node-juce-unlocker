#include <napi.h>
#include "unlocker.h"
#include "crypto.h"


Napi::String unlock(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    const juce::String app_name       (info[0].ToString());
    const juce::String user_email     (info[1].ToString());
    const juce::String username       (info[2].ToString());
    const juce::String machine_number (info[3].ToString());
    const juce::String expiry_time    (info[4].ToString());
    const juce::String private_key    (info[5].ToString());

    const juce::String output = unlocker(app_name, user_email, username, machine_number, expiry_time, private_key);

    return Napi::String::New(env, output.toStdString());
}

Napi::String encrypt(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    const juce::String message (info[0].ToString());
    const juce::String privkey (info[1].ToString());
    const auto output = encryptString(message, juce::RSAKey(privkey));

    return Napi::String::New(env, output.toStdString());
}

Napi::String decrypt(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    const juce::String encryptedMessage (info[0].ToString());
    const juce::String pubkey           (info[1].ToString());
    const auto output = decryptString(encryptedMessage, juce::RSAKey(pubkey));

    return Napi::String::New(env, output.toStdString());
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
