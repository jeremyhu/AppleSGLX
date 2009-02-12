
package require Tcl 8.5

set license {
/*
 Copyright (c) 2008, 2009 Apple Inc.
 
 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation files
 (the "Software"), to deal in the Software without restriction,
 including without limitation the rights to use, copy, modify, merge,
 publish, distribute, sublicense, and/or sell copies of the Software,
 and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:
 
 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT.  IN NO EVENT SHALL THE ABOVE LISTED COPYRIGHT
 HOLDER(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 DEALINGS IN THE SOFTWARE.
 
 Except as contained in this notice, the name(s) of the above
 copyright holders shall not be used in advertising or otherwise to
 promote the sale, use or other dealings in this Software without
 prior written authorization.
*/
}

set this_script [info script]

proc main {argc argv} {
    if {2 != $argc} {
	puts stderr "syntax is: [set ::this_script] serialized-array-file output.h"
	return 1
    }

    set fd [open [lindex $argv 0] r]
    array set api [read $fd]
    close $fd
    
    set fd [open [lindex $argv 1] w]
    
    puts $fd "/* This file was automatically generated by [set ::this_script]. */"
    puts $fd $::license

    puts $fd "
#ifndef APPLE_XGL_API_H
#define APPLE_XGL_API_H
"
    
    puts $fd "struct apple_xgl_api \{"

    set sorted [lsort -dictionary [array names api]]

    foreach f $sorted {
	set attr $api($f)
	set pstr ""

	if {[dict exists $attr alias_for]} {
	    #Skip this function.
	    continue
	}

	foreach p [dict get $attr parameters] {
	    append pstr "[lindex $p 0] [lindex $p 1], "
	}

	set pstr [string trimright $pstr ", "]
	puts $fd "\t[dict get $attr return] (*[set f])([set pstr]);"
    }

    puts $fd "\};"
    puts $fd "void apple_xgl_init_direct(void);

#endif /*APPLE_XGL_API_H*/
"
    
    return 0    
}
exit [main $::argc $::argv]