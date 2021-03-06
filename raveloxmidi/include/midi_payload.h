/*
   This file is part of raveloxmidi.

   Copyright (C) 2014 Dave Kelly

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA 
*/

#ifndef MIDI_PAYLOAD_H
#define MIDI_PAYLOAD_H

typedef struct midi_payload_header_t {
	unsigned char	B;
	unsigned char	J;
	unsigned char	Z;
	unsigned char	P;
	uint16_t	len;
} midi_payload_header_t;

#define PAYLOAD_HEADER_B	0x80
#define PAYLOAD_HEADER_J	0x40
#define PAYLOAD_HEADER_Z	0x20
#define PAYLOAD_HEADER_P	0x10
#define PAYLOAD_HEADER_LEN	0x0f

typedef struct midi_payload_t {
	midi_payload_header_t *header;
	unsigned char	*buffer;
} midi_payload_t;

void midi_payload_destroy( midi_payload_t **payload );
void payload_reset( midi_payload_t **payload );
midi_payload_t * midi_payload_create( void );
void payload_toggle_b( midi_payload_t *payload );
void payload_toggle_j( midi_payload_t *payload );
void payload_toggle_z( midi_payload_t *payload );
void payload_toggle_p( midi_payload_t *payload );
void payload_set_buffer( midi_payload_t *payload, unsigned char *buffer , uint16_t buffer_size);
void payload_dump( midi_payload_t *payload );
void payload_pack( midi_payload_t *payload, unsigned char **buffer, size_t *buffer_size);

#endif
