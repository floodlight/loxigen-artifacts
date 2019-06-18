// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template unit_test.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver15;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.stat.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.oxs.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import static org.junit.Assert.*;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.junit.Test;
import org.junit.runners.Parameterized.Parameters;
import java.util.List;
import com.google.common.collect.ImmutableList;
import org.junit.Before;
import java.util.Set;
import com.google.common.collect.ImmutableSet;
import io.netty.buffer.ByteBuf;
import io.netty.buffer.Unpooled;
import org.hamcrest.CoreMatchers;


@RunWith(Parameterized.class)
public class OFGroupStatsRequestVer15Test {
    OFFactory factory;

    final static byte[] GROUP_STATS_REQUEST_SERIALIZED =
        new byte[] { 0x6, 0x12, 0x0, 0x18, 0x12, 0x34, 0x56, 0x78, 0x0, 0x6, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0 };


    private final static int[] PREFIX_BYTES = { 0, 1, 4, 255, 65335 };
    private final static byte[] EMPTY_BYTES = new byte[65535];

    private final OFMessageReader<?> messageReader;

    @Parameters(name="{index}.MessageReader={0}")
    public static Iterable<Object> data() {
        return ImmutableList.<Object>of(
                OFGroupStatsRequestVer15.READER, OFStatsRequestVer15.READER, OFMessageVer15.READER
        );
    }

    public OFGroupStatsRequestVer15Test(OFMessageReader<?> messageReader) {
        this.messageReader = messageReader;
    }

    @Before
    public void setup() {
        factory = OFFactoryVer15.INSTANCE;
    }

    @Test
    public void testWrite() {
        OFGroupStatsRequest.Builder builder = factory.buildGroupStatsRequest();
        builder
        .setXid(0x12345678)
        .setFlags(ImmutableSet.<OFStatsRequestFlags>of(OFStatsRequestFlags.REQ_MORE))
        .setGroup(OFGroup.of(1))
        .build();
        OFGroupStatsRequest groupStatsRequest = builder.build();
        ByteBuf bb = Unpooled.buffer();
        groupStatsRequest.writeTo(bb);
        byte[] written = new byte[bb.readableBytes()];
        bb.readBytes(written);

        assertThat(written, CoreMatchers.equalTo(GROUP_STATS_REQUEST_SERIALIZED));
    }


    @Test
    public void testRead() throws Exception {
        ByteBuf input = Unpooled.copiedBuffer(GROUP_STATS_REQUEST_SERIALIZED);

        Object groupStatsRequestRead = messageReader.readFrom(input);
        assertThat(groupStatsRequestRead, CoreMatchers.instanceOf(OFGroupStatsRequestVer15.class));
        OFGroupStatsRequest.Builder builder = factory.buildGroupStatsRequest();
        builder
        .setXid(0x12345678)
        .setFlags(ImmutableSet.<OFStatsRequestFlags>of(OFStatsRequestFlags.REQ_MORE))
        .setGroup(OFGroup.of(1))
        .build();
        OFGroupStatsRequest groupStatsRequestBuilt = builder.build();

        assertEquals(GROUP_STATS_REQUEST_SERIALIZED.length, input.readerIndex());

        assertEquals(groupStatsRequestBuilt, groupStatsRequestRead);
        // FIXME: No java stanza in test_data for this class. Add to enable validation of read message
   }

    /**
     * Validates Reader handling of partial messages in the buffer.
     *
     * Ensures that readers deal with partially available messages, and that buffers
     * are returned unmodified. Also checks compatibility when the data is not at the start of
     * the buffer (readerIndex=0), but somewhere else (with the readerIndex appropriately set).
     */
   @Test
   public void testPartialRead() throws Exception {
       ByteBuf msgBuffer = Unpooled.copiedBuffer(GROUP_STATS_REQUEST_SERIALIZED);
       for (int prefixLength: PREFIX_BYTES) {
           ByteBuf prefixBuffer = Unpooled.wrappedBuffer(EMPTY_BYTES).slice(0, prefixLength);
           ByteBuf wholeBuffer = Unpooled.wrappedBuffer(prefixBuffer, msgBuffer);
           for (int partialLength = 0; partialLength < GROUP_STATS_REQUEST_SERIALIZED.length - 1; partialLength++) {
               int length = prefixLength + partialLength;
               ByteBuf slice = wholeBuffer.slice(0, length);
               slice.readerIndex(prefixLength);

               Object read = messageReader.readFrom(slice);

               assertNull("partial message should not be read", read);
               assertEquals("Reader index should be back at the start", prefixLength, slice.readerIndex());
           }

       }
   }

   @Test
   public void testReadWrite() throws Exception {
       ByteBuf input = Unpooled.copiedBuffer(GROUP_STATS_REQUEST_SERIALIZED);

       // FIXME should invoke the overall reader once implemented
       OFGroupStatsRequest groupStatsRequest = (OFGroupStatsRequest) messageReader.readFrom(input);
       assertEquals(GROUP_STATS_REQUEST_SERIALIZED.length, input.readerIndex());

       // write message again
       ByteBuf bb = Unpooled.buffer();
       groupStatsRequest.writeTo(bb);
       byte[] written = new byte[bb.readableBytes()];
       bb.readBytes(written);

       assertThat(written, CoreMatchers.equalTo(GROUP_STATS_REQUEST_SERIALIZED));
   }

}
