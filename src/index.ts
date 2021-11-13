const build  = require("../build/Release/unlocker.node");

export function unlock(appName: string, email: string, username: string,  machineNumber: string,
                       expiryUnixTimeMs: number, jucePrivateKey: string): string {
    return build.unlock(appName, email, username, machineNumber, expiryUnixTimeMs + "", jucePrivateKey);
}

export function encrypt(message: string, jucePrivateKey: string): string {
    return build.encrypt(message, jucePrivateKey);
}

export function decrypt(encryptedMessage: string, jucePublickKey: string): string {
    return build.decrypt(encryptedMessage, jucePublickKey);
}
