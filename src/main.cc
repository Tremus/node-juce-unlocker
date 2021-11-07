#include <napi.h>
#include "unlocker.h"


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

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    // set a function
    exports.Set(
        Napi::String::New(env, "unlock"),
        Napi::Function::New(env, unlock)
    );

    return exports;
}

NODE_API_MODULE(greet, Init)
