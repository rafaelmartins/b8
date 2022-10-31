/*
 * SPDX-FileCopyrightText: 2022 Rafael G. Martins <rafael@rafaelmartins.eng.br>
 * SPDX-License-Identifier: CERN-OHL-S-2.0
 */

thickness = 2;

pcb_width = 84.582;
pcb_length = 36.322;
pcb_screw1_x = 2.921;
pcb_screw1_y = 5.207 + 13.716;
pcb_screw2_x = pcb_screw1_x + 17.018;
pcb_screw2_y = pcb_screw1_y + 12.192;
pcb_screw3_x = pcb_screw2_x + 22.352;
pcb_screw3_y = pcb_screw2_y;
pcb_screw_base_height = 9;
pcb_screw_base_d = 5;
pcb_screw_d = 2;
pcb_padding_x = thickness + 0.5;
pcb_padding_y = thickness + 1;

screw_d = 2;
screw_h = 7;

usb_height = 4.4;
usb_width = 8.2;
usb_distance_x = pcb_padding_x + 19.939 - usb_width / 2;
usb_distance_z = thickness + pcb_screw_base_height + 1.6 - 0.1;

button0_x = 8.890;
button0_y = 6.858;
button_d = 12;
button_distance = 22.352;

led_width = 1.8;
led_length = 1;
led_margin = 1;
led_x = 75.819;
led_y = 17.526;
led_d = 3.2;

gap = thickness * 0.2;

width = pcb_width + 2 * pcb_padding_x + 0.22;  // buttons are slightly out of center :(
length = pcb_length + 2 * pcb_padding_y;
height = usb_distance_z + usb_height + 0.8 + thickness;
