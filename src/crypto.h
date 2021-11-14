#include <juce_product_unlocking/juce_product_unlocking.h>

std::string encryptString (const juce::String& str, juce::RSAKey privateKey)
{
    juce::MemoryOutputStream text;
    text << str;

    juce::BigInteger val;
    val.loadFromMemoryBlock (text.getMemoryBlock());

    privateKey.applyToValue (val);

    return val.toString (16).toStdString();
}

std::string decryptString (juce::String hexData, juce::RSAKey rsaPublicKey)
{
    juce::BigInteger val;
    val.parseString (hexData, 16);

    juce::RSAKey key (rsaPublicKey);
    jassert (key.isValid());

    if (! val.isZero())
    {
        key.applyToValue (val);

        auto mb = val.toMemoryBlock();
        //DBG("mb: " << mb.toString());
        if (juce::CharPointer_UTF8::isValidString (static_cast<const char*> (mb.getData()), (int) mb.getSize()))
            return mb.toString().toStdString();
    }
    jassertfalse;

    return "";
}
