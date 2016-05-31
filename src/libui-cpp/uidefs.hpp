namespace libui {

    enum class DrawBrushType {
        Solid,
        LinearGradient,
        RadialGradient,
        Image,
    };
    
    enum class DrawLineCap {
        Flat,
        Round,
        Square,
    };
    
    enum class DrawLineJoin {
        Miter,
        Round,
        Bevel,
    };
    
    enum class DrawFillMode {
        Winding,
        Alternate,
    };
    
    enum class DrawTextWeight {
        Thin,
        UltraLight,
        Light,
        Book,
        Normal,
        Medium,
        SemiBold,
        Bold,
        UtraBold,
        Heavy,
        UltraHeavy,
    };
    
    enum class DrawTextItalic {
        Normal,
        Oblique,
        Italic,
    };
    
    enum class DrawTextStretch {
        UltraCondensed,
        ExtraCondensed,
        Condensed,
        SemiCondensed,
        Normal,
        SemiExpanded,
        Expanded,
        ExtraExpanded,
        UltraExpanded,
    };
    
    enum class Modifiers {
        Ctrl = 1 << 0,
        Alt = 1 << 1,
        Shift = 1 << 2,
        Super = 1 << 3,
    };
    
    enum class ExtKey {
        Escape = 1,
        Insert,
        Delete,
        Home,
        End,
        PageUp,
        PageDown,
        Up,
        Down,
        Left,
        Right,
        F1,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9,
        F10,
        F11,
        F12,
        N0,
        N1,
        N2,
        N3,
        N4,
        N5,
        N6,
        N7,
        N8,
        N9,
        NDot,
        NEnter,
        NAdd,
        NSubtract,
        NMultiply,
        NDivide,
    };
    
} // namespace libui