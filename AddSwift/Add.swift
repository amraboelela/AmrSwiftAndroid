@_cdecl("myMain")
public func myMain()
{

    // Now the fun can begin!
    // <Your Swift code starts here ...>

    let four = 2 + 2
    // TODO/FIXME: print goes to /dev/null on Android
    print("2 + 2 = \(four)")

    // Remember to not block the event loop
}

@_cdecl("addTwoNumbers")
public func addTwoNumbers(first: UInt8, second: UInt8) -> UInt8 {
    return first + second
}
