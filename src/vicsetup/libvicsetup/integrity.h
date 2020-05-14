#ifndef _VIC_INTEGRITY_H
#define _VIC_INTEGRITY_H

#include <stdint.h>
#include "defs.h"
#include "vic.h"

VIC_PACK_BEGIN
typedef struct _vic_integrity_sb
{
  /* "integrt" */
  uint8_t magic[8];

  /* superblock version, 1,2 or 3 */
  uint8_t version;

  /* interleave sectors */
  int8_t log2_interleave_sectors;

  /* tag size per-sector */
  uint16_t integrity_tag_size;

  /* size of journal */
  uint32_t journal_sections;

  /* available size for data */
  uint64_t provided_data_sectors;

  /* flags */
  uint32_t flags;

  /* presented block (sector) size */
  uint8_t log2_sectors_per_block;

  /* blocks per bitmap, V3 superblock only */
  uint8_t log2_blocks_per_bitmap_bit;

  uint8_t pad[2];

  /* current recalculate sector, V2 superblock only */
  uint64_t recalc_sector;
}
vic_integrity_sb_t;
VIC_PACK_END

vic_result_t vic_read_integrity_sb(
    vic_blockdev_t* device,
    uint64_t offset,
    vic_integrity_sb_t* sb);

vic_result_t vic_dump_integrity_sb(const vic_integrity_sb_t* sb);

const char* vic_integrity_name(vic_integrity_t integrity);

size_t vic_integrity_tag_size(vic_integrity_t integrity);

vic_integrity_t vic_integrity_enum(const char* str);

size_t vic_integrity_tag_size_from_str(const char* integrity);

size_t vic_integrity_key_size(vic_integrity_t integrity);

size_t vic_integrity_key_size_from_str(const char* integrity);

#endif /* _VIC_INTEGRITY_H */