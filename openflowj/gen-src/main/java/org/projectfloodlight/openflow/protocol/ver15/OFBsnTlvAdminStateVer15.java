// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
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
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFBsnTlvAdminStateVer15 implements OFBsnTlvAdminState {
    private static final Logger logger = LoggerFactory.getLogger(OFBsnTlvAdminStateVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int LENGTH = 5;


    // OF message fields
    private final OFBsnAdminState value;
//

    // package private constructor - used by readers, builders, and factory
    OFBsnTlvAdminStateVer15(OFBsnAdminState value) {
        if(value == null) {
            throw new NullPointerException("OFBsnTlvAdminStateVer15: property value cannot be null");
        }
        this.value = value;
    }

    // Accessors for OF message fields
    @Override
    public int getType() {
        return 0xd8;
    }

    @Override
    public OFBsnAdminState getValue() {
        return value;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFBsnTlvAdminState.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBsnTlvAdminState.Builder {
        final OFBsnTlvAdminStateVer15 parentMessage;

        // OF message fields
        private boolean valueSet;
        private OFBsnAdminState value;

        BuilderWithParent(OFBsnTlvAdminStateVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public int getType() {
        return 0xd8;
    }

    @Override
    public OFBsnAdminState getValue() {
        return value;
    }

    @Override
    public OFBsnTlvAdminState.Builder setValue(OFBsnAdminState value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFBsnTlvAdminState build() {
                OFBsnAdminState value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");

                //
                return new OFBsnTlvAdminStateVer15(
                    value
                );
        }

    }

    static class Builder implements OFBsnTlvAdminState.Builder {
        // OF message fields
        private boolean valueSet;
        private OFBsnAdminState value;

    @Override
    public int getType() {
        return 0xd8;
    }

    @Override
    public OFBsnAdminState getValue() {
        return value;
    }

    @Override
    public OFBsnTlvAdminState.Builder setValue(OFBsnAdminState value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFBsnTlvAdminState build() {
            if(!this.valueSet)
                throw new IllegalStateException("Property value doesn't have default value -- must be set");
            if(value == null)
                throw new NullPointerException("Property value must not be null");


            return new OFBsnTlvAdminStateVer15(
                    value
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFBsnTlvAdminState> {
        @Override
        public OFBsnTlvAdminState readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 0xd8
            short type = bb.readShort();
            if(type != (short) 0xd8)
                throw new OFParseError("Wrong type: Expected=0xd8(0xd8), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 5)
                throw new OFParseError("Wrong length: Expected=5(5), got="+length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            OFBsnAdminState value = OFBsnAdminStateSerializerVer15.readFrom(bb);

            OFBsnTlvAdminStateVer15 bsnTlvAdminStateVer15 = new OFBsnTlvAdminStateVer15(
                    value
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bsnTlvAdminStateVer15);
            return bsnTlvAdminStateVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBsnTlvAdminStateVer15Funnel FUNNEL = new OFBsnTlvAdminStateVer15Funnel();
    static class OFBsnTlvAdminStateVer15Funnel implements Funnel<OFBsnTlvAdminStateVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBsnTlvAdminStateVer15 message, PrimitiveSink sink) {
            // fixed value property type = 0xd8
            sink.putShort((short) 0xd8);
            // fixed value property length = 5
            sink.putShort((short) 0x5);
            OFBsnAdminStateSerializerVer15.putTo(message.value, sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBsnTlvAdminStateVer15> {
        @Override
        public void write(ByteBuf bb, OFBsnTlvAdminStateVer15 message) {
            // fixed value property type = 0xd8
            bb.writeShort((short) 0xd8);
            // fixed value property length = 5
            bb.writeShort((short) 0x5);
            OFBsnAdminStateSerializerVer15.writeTo(bb, message.value);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBsnTlvAdminStateVer15(");
        b.append("value=").append(value);
        b.append(")");
        return b.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFBsnTlvAdminStateVer15 other = (OFBsnTlvAdminStateVer15) obj;

        if (value == null) {
            if (other.value != null)
                return false;
        } else if (!value.equals(other.value))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((value == null) ? 0 : value.hashCode());
        return result;
    }

}
