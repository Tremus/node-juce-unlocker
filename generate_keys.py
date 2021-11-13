# pip install rsa

import rsa

def int_to_hex(integer: int) -> str:
    return hex(integer)[2:]

NUM_BITS = 1 << 10 # 1024
print("## BITS %d ##" % NUM_BITS)

(pubkey, privkey) = rsa.newkeys(NUM_BITS)

print("## AS PRIMES ##")
print('n:', privkey.n)
print('e:', privkey.e)
print('d:', privkey.d)
print('p:', privkey.p)
print('q:', privkey.q)

print("## AS HEXES ##")
print('n:', int_to_hex(privkey.n))
print('e:', int_to_hex(privkey.e))
print('d:', int_to_hex(privkey.d))
print('p:', int_to_hex(privkey.p))
print('q:', int_to_hex(privkey.q))

print("## JUCE PUBLIC KEY ##")
print("juce::RSAKey(\"%s\");" % ("%s,%s" % (int_to_hex(privkey.e), int_to_hex(privkey.n))))
print("## JUCE PRIVATE KEY ##")
print("juce::RSAKey(\"%s\");" % ("%s,%s" % (int_to_hex(privkey.d), int_to_hex(privkey.n))))
