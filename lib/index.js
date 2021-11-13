"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.decrypt = exports.encrypt = exports.unlock = void 0;
var build = require("../build/Release/unlocker.node");
function unlock(appName, email, username, machineNumber, expiryUnixTimeMs, jucePrivateKey) {
    return build.unlock(appName, email, username, machineNumber, expiryUnixTimeMs + "", jucePrivateKey);
}
exports.unlock = unlock;
function encrypt(message, jucePrivateKey) {
    return build.encrypt(message, jucePrivateKey);
}
exports.encrypt = encrypt;
function decrypt(encryptedMessage, jucePublickKey) {
    return build.decrypt(encryptedMessage, jucePublickKey);
}
exports.decrypt = decrypt;
//# sourceMappingURL=index.js.map