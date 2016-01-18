all: make_keybag
	
make_keybag:
	@rm -rf tools/;
	@echo Compiling make_keybag…;
	@mkdir tools/;
	@xcrun -sdk iphoneos clang --sysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk src/make_keybag.c -arch armv7 -framework MobileKeyBag -O2 -F/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/System/Library/PrivateFrameworks -Wall -o tools/make_keybag -miphoneos-version-min=6.0;
	@ldid -S tools/make_keybag;
	@echo Compiled and signed.;
