// mode-specific defaults, constraints and functions
//
// david lindecrantz <optiroc@gmail.com>

#pragma once

#include "Color.h"

namespace sfc {

enum class Mode {
  none,
  snes,
  snes_mode7,
  gb,
  gbc,
  gba,
  gba_affine,
  md,
  pce,
  pce_sprite
};

inline Mode mode(const std::string& str) {
  if (str == "snes") {
    return Mode::snes;
  } else if (str == "snes_mode7") {
    return Mode::snes_mode7;
  } else if (str == "gb") {
    return Mode::gb;
  } else if (str == "gbc") {
    return Mode::gbc;
  } else if (str == "gba") {
    return Mode::gba;
  } else if (str == "gba_affine") {
    return Mode::gba_affine;
  } else if (str == "md") {
    return Mode::md;
  } else if (str == "pce") {
    return Mode::pce;
  } else if (str == "pce_sprite") {
    return Mode::pce_sprite;
  }
  return Mode::none;
}

inline std::string mode(Mode mode) {
  switch (mode) {
  case Mode::snes:
    return std::string("snes");
  case Mode::snes_mode7:
    return std::string("snes_mode7");
  case Mode::gb:
    return std::string("gb");
  case Mode::gbc:
    return std::string("gbc");
  case Mode::gba:
    return std::string("gba");
  case Mode::gba_affine:
    return std::string("gba_affine");
  case Mode::md:
    return std::string("md");
  case Mode::pce:
    return std::string("pce");
  case Mode::pce_sprite:
    return std::string("pce_sprite");
  case Mode::none:
    return std::string("none");
  }
}

constexpr unsigned default_bpp_for_mode(Mode mode) {
  switch (mode) {
  case Mode::snes:
    return 4;
  case Mode::snes_mode7:
    return 8;
  case Mode::gb:
  case Mode::gbc:
    return 2;
  case Mode::gba:
    return 4;
  case Mode::gba_affine:
    return 8;
  case Mode::md:
  case Mode::pce:
  case Mode::pce_sprite:
    return 4;
  case Mode::none:
    return 4;
  }
}

constexpr bool bpp_allowed_for_mode(unsigned bpp, Mode mode) {
  switch (mode) {
  case Mode::snes:
    return bpp == 2 || bpp == 4 || bpp == 8;
  case Mode::snes_mode7:
    return bpp == 8;
  case Mode::gb:
  case Mode::gbc:
    return bpp == 2;
  case Mode::gba:
    return bpp == 4 || bpp == 8;
  case Mode::gba_affine:
    return bpp == 8;
  case Mode::md:
  case Mode::pce:
  case Mode::pce_sprite:
    return bpp == 4;
  case Mode::none:
    return false;
  }
}

constexpr unsigned default_tile_size_for_mode(Mode mode) {
  switch (mode) {
  case Mode::pce_sprite:
    return 16;
  default:
    return 8;
  }
}

constexpr unsigned max_tile_count_for_mode(Mode mode) {
  switch (mode) {
  case Mode::snes:
    return 1024;
  case Mode::snes_mode7:
    return 256;
  case Mode::gb:
    return 256;
  case Mode::gbc:
    return 512;
  case Mode::gba:
    return 1024;
  case Mode::gba_affine:
    return 256;
  case Mode::md:
  case Mode::pce:
    return 2048;
  case Mode::pce_sprite:
    return 0;
  case Mode::none:
    return 0;
  }
}

constexpr bool tile_width_allowed_for_mode(unsigned width, Mode mode) {
  switch (mode) {
  case Mode::snes:
    return width == 8 || width == 16;
  case Mode::snes_mode7:
  case Mode::gb:
  case Mode::gbc:
  case Mode::gba:
  case Mode::gba_affine:
  case Mode::md:
  case Mode::pce:
    return width == 8;
  case Mode::pce_sprite:
    return width == 16;
  case Mode::none:
    return false;
  }
}

constexpr bool tile_height_allowed_for_mode(unsigned height, Mode mode) {
  switch (mode) {
  case Mode::snes:
    return height == 8 || height == 16;
  case Mode::snes_mode7:
  case Mode::gb:
  case Mode::gbc:
  case Mode::gba:
  case Mode::gba_affine:
  case Mode::md:
  case Mode::pce:
    return height == 8;
  case Mode::pce_sprite:
    return height == 16;
  case Mode::none:
    return false;
  }
}

constexpr bool tile_flipping_allowed_for_mode(Mode mode) {
  switch (mode) {
  case Mode::snes:
  case Mode::gbc:
  case Mode::gba:
  case Mode::md:
    return true;
  case Mode::snes_mode7:
  case Mode::gb:
  case Mode::gba_affine:
  case Mode::pce:
  case Mode::pce_sprite:
    return false;
  case Mode::none:
    return false;
  }
}

constexpr unsigned default_map_size_for_mode(Mode mode) {
  switch (mode) {
  case Mode::snes:
  case Mode::gb:
  case Mode::gbc:
  case Mode::gba:
  case Mode::gba_affine:
  case Mode::md:
  case Mode::pce:
    return 32;
  case Mode::snes_mode7:
    return 128;
  case Mode::pce_sprite:
    return 0;
  case Mode::none:
    return 0;
  }
}

constexpr unsigned default_palette_count_for_mode(Mode mode) {
  switch (mode) {
  case Mode::snes:
    return 8;
  case Mode::snes_mode7:
    return 1;
  case Mode::gb:
    return 1;
  case Mode::gbc:
    return 8;
  case Mode::gba:
    return 16;
  case Mode::gba_affine:
    return 1;
  case Mode::md:
    return 4;
  case Mode::pce:
  case Mode::pce_sprite:
    return 16;
  case Mode::none:
    return 0;
  }
}

constexpr bool col0_is_shared_for_mode(Mode mode) {
  switch (mode) {
  case Mode::snes:
  case Mode::snes_mode7:
  case Mode::gba:
  case Mode::gba_affine:
  case Mode::md:
  case Mode::pce_sprite:
    return true;
  case Mode::gb:
  case Mode::gbc:
    return false;
  case Mode::pce:
    return true;
  case Mode::none:
    return true;
  }
}

constexpr bool col0_is_shared_for_sprite_mode(Mode mode) {
  switch (mode) {
  case Mode::snes:
  case Mode::snes_mode7:
  case Mode::gb:
  case Mode::gbc:
  case Mode::gba:
  case Mode::gba_affine:
  case Mode::md:
  case Mode::pce:
  case Mode::pce_sprite:
    return true;
  case Mode::none:
    return false;
  }
}

//
// mode-specific color transformations
//

// scale standard rgba color to mode-specific range
inline rgba_u32 reduce_color(const rgba_u32 color, Mode to_mode) {
  switch (to_mode) {
  case Mode::snes:
  case Mode::snes_mode7:
  case Mode::gbc:
  case Mode::gba:
  case Mode::gba_affine:
    if (((color & 0xff000000) >> 24) < 0x80) {
      return transparent_color;
    } else {
      rgba_color c(color);
      c.r >>= 3;
      c.g >>= 3;
      c.b >>= 3;
      rgba_u32 scaled = c;
      return (scaled & 0x00ffffff) + 0xff000000;
    }
    break;
  case Mode::gb:
    {
      rgba_color c(color);
      channel_t gray = c.r * 0.299 + c.g * 0.587 + c.b * 0.114;
      if (gray <= 0x40) gray = 0;
      else if (gray <= 0x80) gray = 1;
      else if (gray <= 0xc0) gray = 2;
      else gray = 3;
      c.r = c.g = c.b = gray;
      rgba_u32 scaled = c;
      return (scaled & 0x00ffffff) + 0xff000000;
      break;
    }
  case Mode::md:
  case Mode::pce:
  case Mode::pce_sprite:
    if (((color & 0xff000000) >> 24) < 0x80) {
      return transparent_color;
    } else {
      rgba_color c(color);
      c.r >>= 5;
      c.g >>= 5;
      c.b >>= 5;
      rgba_u32 scaled = c;
      return (scaled & 0x00ffffff) + 0xff000000;
    }
    break;
  case Mode::none:
    return 0;
  }
}

// scale standard rgba colors to mode-specific range
inline rgba_u32_vec reduce_colors(const rgba_u32_vec& colors, Mode to_mode) {
  auto vc = colors;
  for (rgba_u32& color : vc)
    color = reduce_color(color, to_mode);
  return vc;
}

inline rgba_u32_set reduce_colors(const rgba_u32_set& colors, Mode to_mode) {
  auto sc = rgba_u32_set();
  for (const rgba_u32& color : colors)
    sc.insert(reduce_color(color, to_mode));
  return sc;
}

// scale color from mode-specific range to 8bpc RGBA range
inline rgba_u32 normalize_color(const rgba_u32 color, Mode from_mode) {
  rgba_color c(color);
  switch (from_mode) {
  case Mode::snes:
  case Mode::snes_mode7:
  case Mode::gbc:
  case Mode::gba:
  case Mode::gba_affine:
    c.r = scale_up(c.r, 3);
    c.g = scale_up(c.g, 3);
    c.b = scale_up(c.b, 3);
    c.a = scale_up(c.a, 3);
    return c;
  case Mode::gb:
    c.r = scale_up(c.r, 6);
    c.g = scale_up(c.g, 6);
    c.b = scale_up(c.b, 6);
    c.a = scale_up(c.a, 6);
    return c;
  case Mode::md:
  case Mode::pce:
  case Mode::pce_sprite:
    c.r = scale_up(c.r, 5);
    c.g = scale_up(c.g, 5);
    c.b = scale_up(c.b, 5);
    c.a = scale_up(c.a, 5);
    return c;
  case Mode::none:
    return 0;
  }
}

// scale colors from mode-specific range to 8bpc RGBA range
inline rgba_u32_vec normalize_colors(const rgba_u32_vec& colors, Mode from_mode) {
  auto vc = colors;
  for (rgba_u32& color : vc)
    color = normalize_color(color, from_mode);
  return vc;
}

//
// to/from native color data
//

// pack scaled rgba color to native format
inline byte_vec pack_native_color(const rgba_u32 color, Mode mode) {
  byte_vec v;
  switch (mode) {
  case Mode::snes:
  case Mode::snes_mode7:
  case Mode::gbc:
  case Mode::gba:
  case Mode::gba_affine:
    v.push_back((color & 0x1f) | ((color >> 3) & 0xe0));
    v.push_back(((color >> 11) & 0x03) | ((color >> 14) & 0x7c));
    break;
  case Mode::gb:
    v.push_back((0xff - (color & 0x3)) & 0x3);
    break;
  case Mode::md:
    v.push_back(((color << 1) & 0x0e) | ((color >> 3) & 0xe0));
    v.push_back(((color >> 15) & 0x0e));
    break;
  case Mode::pce:
  case Mode::pce_sprite:
    v.push_back(((color >> 16) & 0x07) | (color << 3 & 0x38) | ((color >> 2) & 0xc0));
    v.push_back((color >> 10) & 0x01);
    break;
  case Mode::none:
    break;
  }
  return v;
}

// pack scaled rgba colors to native format
inline byte_vec pack_native_colors(const rgba_u32_vec& colors, Mode mode) {
  byte_vec data;

  if (mode == Mode::gb) {
    if (colors.size() != 4) {
      throw std::runtime_error("gb palette size not equal to 4");
    }
    uint8_t c = pack_native_color(colors[0], mode)[0];
    c |= pack_native_color(colors[1], mode)[0] << 2;
    c |= pack_native_color(colors[2], mode)[0] << 4;
    c |= pack_native_color(colors[3], mode)[0] << 6;
    data.push_back(c);

  } else {
    for (const auto& c : colors) {
      auto nc = pack_native_color(c, mode);
      data.insert(data.end(), nc.begin(), nc.end());
    }
  }
  return data;
}

// unpack native format color to (scaled) rgba color
inline rgba_u32_vec unpack_native_colors(const byte_vec& colors, Mode mode) {
  rgba_u32_vec v;
  switch (mode) {
  case Mode::snes:
  case Mode::snes_mode7:
  case Mode::gbc:
  case Mode::gba:
  case Mode::gba_affine:
    if (colors.size() % 2 != 0) {
      throw std::runtime_error("native palette size not a multiple of 2");
    }
    for (unsigned i = 0; i < colors.size(); i += 2) {
      uint16_t cw = (colors[i + 1] << 8) + colors[i];
      rgba_u32 nc = (cw & 0x001f) | ((cw & 0x03e0) << 3) | ((cw & 0x7c00) << 6) | 0xff000000;
      v.push_back(nc);
    }
    break;
  case Mode::gb:
    if (colors.size() != 1) {
      throw std::runtime_error("native palette size not one byte");
    }
    for (unsigned i = 0; i < 4; ++i) {
      rgba_u32 rgba;
      switch ((colors[0] >> (i * 2)) & 0x3) {
        case 0: rgba = 0xff030303; break;
        case 1: rgba = 0xff020202; break;
        case 2: rgba = 0xff010101; break;
        case 3: rgba = 0xff000000; break;
        default:
          rgba = 0;
      }
      v.push_back(rgba);
    }
    break;
  case Mode::md:
    if (colors.size() % 2 != 0) {
      throw std::runtime_error("native palette size not a multiple of 2");
    }
    for (unsigned i = 0; i < colors.size(); i += 2) {
      uint16_t cw = (colors[i + 1] << 8) + colors[i];
      rgba_u32 nc = ((cw & 0x00e) >> 1) | ((cw & 0x00e0) << 3) | ((cw & 0x0e00) << 7) | 0xff000000;
      v.push_back(nc);
    }
    break;
  case Mode::pce:
  case Mode::pce_sprite:
    if (colors.size() % 2 != 0) {
      throw std::runtime_error("native palette size not a multiple of 2");
    }
    for (unsigned i = 0; i < colors.size(); i += 2) {
      uint16_t cw = (colors[i + 1] << 8) + colors[i];
      rgba_u32 nc = ((cw & 0x0038) >> 3) | ((cw & 0x0007) << 8) | ((cw & 0x1c00) << 10) | 0xff000000;
      v.push_back(nc);
    }
    break;
  case Mode::none:
    break;
  }
  return v;
}

//
// to/from native tile data
//

inline byte_vec pack_native_tile(const index_vec& data, Mode mode, unsigned bpp, unsigned width, unsigned height) {

  // snes/gameboy style bit planes
  auto make_2bit_planes = [](const index_vec& in_data, unsigned plane_index) {
    byte_vec p(16);
    if (in_data.empty())
      return p;

    index_t mask0 = 1;
    for (unsigned i = 0; i < plane_index; ++i)
      mask0 <<= 1;
    index_t mask1 = mask0 << 1;

    unsigned shift0 = plane_index;
    unsigned shift1 = plane_index + 1;

    for (unsigned y = 0; y < 8; ++y) {
      for (unsigned x = 0; x < 8; ++x) {
        p[y * 2 + 0] |= ((in_data[y * 8 + x] & mask0) >> shift0) << (7 - x);
        p[y * 2 + 1] |= ((in_data[y * 8 + x] & mask1) >> shift1) << (7 - x);
      }
    }
    return p;
  };

  // regular bit planes
  auto make_1bit_planes = [](const index_vec& in_data, unsigned plane) {
    if (in_data.size() % 8)
      throw std::runtime_error("programmer error (in_data not multiple of 8 in make_1bit_planes)");

    size_t plane_size = in_data.size() >> 3;
    byte_vec p(plane_size);

    index_t mask = 1;
    for (unsigned i = 0; i < plane; ++i)
      mask <<= 1;

    for (unsigned index_b = 0, index_i = 0; index_b < plane_size; ++index_b) {
      index_t byte = 0;
      for (unsigned b = 0; b < 8; ++b) {
        if (in_data[index_i + b] & mask)
          byte |= 1 << b;
      }
      p[index_b] = byte;
      index_i += 8;
    }
    return p;
  };

  // gba/md style 2 pixels per byte data
  auto make_4bpp_bitpack = [](const index_vec& in_data) {
    if (in_data.size() % 2)
      throw std::runtime_error("programmer error (in_data not multiple of 2 in make_4bpp_bitpack)");

    byte_vec bv(in_data.size() >> 1);
    for (unsigned i = 0; i < bv.size(); ++i)
      bv[i] = (0x0f & in_data[i << 1]) | (0xf0 & (in_data[(i << 1) + 1] << 4));

    return bv;
  };

  byte_vec nd;

  if (mode == Mode::snes || mode == Mode::gb || mode == Mode::gbc || mode == Mode::pce) {
    if (width != 8 || height != 8)
      throw std::runtime_error(
        fmt::format("programmer error (tile size not 8x8 in pack_native_tile() for mode \"{}\")", sfc::mode(mode)));

    unsigned planes = bpp >> 1;
    for (unsigned i = 0; i < planes; ++i) {
      auto plane = make_2bit_planes(data, i * 2);
      nd.insert(nd.end(), plane.begin(), plane.end());
    }

  } else if (mode == Mode::snes_mode7) {
    nd = data;

  } else if (mode == Mode::gba || mode == Mode::gba_affine || mode == Mode::md) {
    if (bpp == 8) {
      nd = data;
    } else if (bpp == 4) {
      nd = make_4bpp_bitpack(data);
    }

  } else if (mode == Mode::pce_sprite) {
    for (unsigned p = 0; p < 4; ++p) {
      auto plane = make_1bit_planes(data, p);
      nd.insert(nd.end(), plane.begin(), plane.end());
    }
  }

  return nd;
}

inline index_vec unpack_native_tile(const byte_vec& data, Mode mode, unsigned bpp, unsigned width, unsigned height) {

  auto add_1bit_plane = [](index_vec& out_data, const byte_vec& in_data, unsigned plane_index) {
    int plane_offset = ((plane_index >> 1) * 16) + (plane_index & 1);
    for (int y = 0; y < 8; ++y) {
      for (int x = 0; x < 8; ++x) {
        out_data[y * 8 + x] += ((in_data[plane_offset + (y * 2)] >> (7 - x)) & 1) << plane_index;
      }
    }
  };

  index_vec ud(width * height);

  if (mode == Mode::snes || mode == Mode::gb || mode == Mode::gbc || mode == Mode::pce) {
    for (unsigned i = 0; i < bpp; ++i)
      add_1bit_plane(ud, data, i);

  } else if (mode == Mode::snes_mode7) {
    ud = data;

  } else if (mode == Mode::gba || mode == Mode::gba_affine || mode == Mode::md) {
    if (bpp == 4) {
      for (unsigned i = 0; i < data.size(); ++i) {
        ud[(i << 1) + 0] = data[i] & 0x0f;
        ud[(i << 1) + 1] = (data[i] & 0xf0) >> 4;
      }
    } else {
      ud = data;
    }

  } else if (mode == Mode::pce_sprite) {
    // TODO: read pce_sprite data
    throw std::runtime_error("Using pce_sprite native data as input not implemented");
  }

  return ud;
}

} /* namespace sfc */
