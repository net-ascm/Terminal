/*++
Copyright (c) Microsoft Corporation

Module Name:
- Profile.hpp

Abstract:
- A profile acts as a single set of terminal settings. Many tabs or panes could
     exist side-by-side with different profiles simultaneously.

Author(s):
- Mike Griese - March 2019

--*/
#pragma once
#include "ColorScheme.h"

namespace Microsoft::Terminal::TerminalApp
{
    class Profile;
};

class Microsoft::Terminal::TerminalApp::Profile final
{

public:
    Profile();
    ~Profile();

    winrt::Microsoft::Terminal::Settings::TerminalSettings CreateTerminalSettings(const std::vector<::Microsoft::Terminal::TerminalApp::ColorScheme>& schemes) const;

    winrt::Windows::Data::Json::JsonObject ToJson() const;
    static Profile FromJson(winrt::Windows::Data::Json::JsonObject json);

    GUID GetGuid() const noexcept;
    std::wstring GetName() const noexcept;

    void SetFontFace(std::wstring fontFace) noexcept;
    void SetColorScheme(std::optional<std::wstring> schemeName) noexcept;
    void SetAcrylicOpacity(double opacity) noexcept;
    void SetCommandline(std::wstring cmdline) noexcept;
    void SetName(std::wstring name) noexcept;
    void SetUseAcrylic(bool useAcrylic) noexcept;
    void SetDefaultForeground(COLORREF defaultForeground) noexcept;
    void SetDefaultBackground(COLORREF defaultBackground) noexcept;

private:

    GUID _guid;
    std::wstring _name;

    // If this is set, then our colors should come from the associated color scheme
    std::optional<std::wstring> _schemeName;

    uint32_t _defaultForeground;
    uint32_t _defaultBackground;
    std::array<uint32_t, COLOR_TABLE_SIZE> _colorTable;
    int32_t _historySize;
    int32_t _initialRows;
    int32_t _initialCols;
    bool _snapOnInput;

    std::wstring _commandline;
    std::wstring _fontFace;
    int32_t _fontSize;
    double _acrylicTransparency;
    bool _useAcrylic;

    //MSFT:20738109: Scrollbar state should be an enum: Always Visible, Reveal on Hover, Always Hide
    bool _showScrollbars;

};
