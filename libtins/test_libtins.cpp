#include <iostream>
#include <vector>
#include <string>
#include <tins/tins.h>
#include <gtest/gtest.h>

namespace {

bool callback(const Tins::PDU &pdu) {
    std::cout << "Sniffing started!" << "\n";
    // Find the IP layer
    const Tins::IP &ip = pdu.rfind_pdu<Tins::IP>(); 
    // Find the TCP layer
    const Tins::TCP &tcp = pdu.rfind_pdu<Tins::TCP>(); 
    std::wcout << ip.src_addr() << ':' << tcp.sport() << " -> " 
        << ip.dst_addr() << ':' << tcp.dport() << "\n";
    return false;
}

TEST(LibtinsTest, BasicSniffer) {

    // First fetch all network interfaces
    std::vector<Tins::NetworkInterface> interfaces = Tins::NetworkInterface::all();

    std::cout << "\nAvailable interfaces:\n";
    // Now iterate them
    for (const Tins::NetworkInterface& iface : interfaces) {
        // First print the name (GUID)
        std::cout << iface.name();

        // Now print the friendly name, a wstring that will contain something like 
        // "Local Area Connection 2"
        std::wcout << " (" << iface.friendly_name() << ")\n";
    }
    std::cout << "\n";

    if (interfaces.size() < 1 || (interfaces.size() == 1 && interfaces.front().name() == "lo")) {
        std::cerr << "Either none or only loopback device found.\n";
        FAIL();
    }

    std::string first_device = interfaces.front().name();

    std::cout << "Attempting to open Sniffer using device \"" << first_device << "\"...\n";

    try {
        Tins::Sniffer(first_device).sniff_loop(callback);
    }
    catch (std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        FAIL();
    }

    SUCCEED();
}

} // namespace