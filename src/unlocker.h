#include <regex>
#include <juce_product_unlocking/juce_product_unlocking.h>


//==============================================================================
std::string unlocker (const juce::String& app_name,       // name of the product being unlocked
                      const juce::String& user_email,     // user's email address
                      const juce::String& username,       // name of the user. Careful not to allow any spaces!
                      const juce::String& machine_number, // a comma- or semicolon-separated list of all machine ID strings this user can run this product on (no whitespace between items!)
                      const juce::String& expiry_time,    // epoch time in milliseconds
                      const juce::String& private_key)    // the RSA private key corresponding to the public key you've used in the app
{
    // TODO: get rid of this junk. do this stuff in JS
    if (expiry_time.length() != 13 || ! std::regex_match(expiry_time.toRawUTF8(), std::regex("^[0-9]+$")))
    {
        std::cout << "\"" << expiry_time << "\"(" << expiry_time.length() << ") is not a valid epoch time." << std::endl;
        return "";
    }
    // ensure private key is valid
    if (! std::regex_match(private_key.toRawUTF8(), std::regex("^[0-9a-f]+,[0-9a-f]+$")))
    {
        std::cout << "Not a valid RSA key!" << std::endl;
        return "";
    }

//! [Unlocker]
    // args[0]: app-name
    // args[1]: user-email
    // args[2]: username
    // args[3]: machine-numbers
    // args[4]: expiry-time
    // args[5]: private-key

    //std::cout << juce::KeyGeneration::generateKeyFile (args[0], args[1], args[2], args[3], juce::RSAKey (args[4])) << std::endl;

    auto expiryTime = juce::Time(expiry_time.getLargeIntValue());
    // std::cout << juce::KeyGeneration::generateExpiringKeyFile (args[0], args[1], args[2], args[3], expiryTime, juce::RSAKey (args[5])) << std::endl;
    const juce::String output = juce::KeyGeneration::generateExpiringKeyFile (app_name, user_email, username, machine_number, expiryTime, juce::RSAKey (private_key));

    return output.toStdString();
//! [Unlocker]
}
