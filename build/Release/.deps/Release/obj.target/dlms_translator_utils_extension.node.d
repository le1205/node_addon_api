cmd_Release/obj.target/dlms_translator_utils_extension.node := g++ -o Release/obj.target/dlms_translator_utils_extension.node -shared -pthread -rdynamic -m64  -Wl,-soname=dlms_translator_utils_extension.node -Wl,--start-group Release/obj.target/dlms_translator_utils_extension/dlms_translator_utils_wrapper.o Release/obj.target/node_modules/node-addon-api/nothing.a -Wl,--end-group -L /home/legend/Documents/node_addon_api/src/lib -lgurux_dlms -lxml2