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

class OFOxmActsetOutputVer15 implements OFOxmActsetOutput {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmActsetOutputVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int LENGTH = 5;

        private final static OFPort DEFAULT_VALUE = OFPort.ANY;

    // OF message fields
    private final OFPort value;
//
    // Immutable default instance
    final static OFOxmActsetOutputVer15 DEFAULT = new OFOxmActsetOutputVer15(
        DEFAULT_VALUE
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmActsetOutputVer15(OFPort value) {
        if(value == null) {
            throw new NullPointerException("OFOxmActsetOutputVer15: property value cannot be null");
        }
        this.value = value;
    }

    // Accessors for OF message fields
    @Override
    public long getTypeLen() {
        return 0x80005604L;
    }

    @Override
    public OFPort getValue() {
        return value;
    }

    @Override
    public MatchField<OFPort> getMatchField() {
        return MatchField.ACTSET_OUTPUT;
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    public OFOxm<OFPort> getCanonical() {
        // exact match OXM is always canonical
        return this;
    }

    @Override
    public OFPort getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.5");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFOxmActsetOutput.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmActsetOutput.Builder {
        final OFOxmActsetOutputVer15 parentMessage;

        // OF message fields
        private boolean valueSet;
        private OFPort value;

        BuilderWithParent(OFOxmActsetOutputVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getTypeLen() {
        return 0x80005604L;
    }

    @Override
    public OFPort getValue() {
        return value;
    }

    @Override
    public OFOxmActsetOutput.Builder setValue(OFPort value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public MatchField<OFPort> getMatchField() {
        return MatchField.ACTSET_OUTPUT;
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public OFOxm<OFPort> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.5");
    }

    @Override
    public OFPort getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.5");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFOxmActsetOutput build() {
                OFPort value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");

                //
                return new OFOxmActsetOutputVer15(
                    value
                );
        }

    }

    static class Builder implements OFOxmActsetOutput.Builder {
        // OF message fields
        private boolean valueSet;
        private OFPort value;

    @Override
    public long getTypeLen() {
        return 0x80005604L;
    }

    @Override
    public OFPort getValue() {
        return value;
    }

    @Override
    public OFOxmActsetOutput.Builder setValue(OFPort value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public MatchField<OFPort> getMatchField() {
        return MatchField.ACTSET_OUTPUT;
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public OFOxm<OFPort> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.5");
    }

    @Override
    public OFPort getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.5");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFOxmActsetOutput build() {
            OFPort value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");


            return new OFOxmActsetOutputVer15(
                    value
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader extends AbstractOFMessageReader<OFOxmActsetOutput> {
        @Override
        public OFOxmActsetOutput readFrom(OFMessageReaderContext context, ByteBuf bb) throws OFParseError {
            if(bb.readableBytes() < LENGTH)
                return null;
            // fixed value property typeLen == 0x80005604L
            int typeLen = bb.readInt();
            if(typeLen != (int) 0x80005604)
                throw new OFParseError("Wrong typeLen: Expected=0x80005604L(0x80005604L), got="+typeLen);
            OFPort value = OFPort.read4Bytes(bb);

            OFOxmActsetOutputVer15 oxmActsetOutputVer15 = new OFOxmActsetOutputVer15(
                    value
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmActsetOutputVer15);
            return oxmActsetOutputVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmActsetOutputVer15Funnel FUNNEL = new OFOxmActsetOutputVer15Funnel();
    static class OFOxmActsetOutputVer15Funnel implements Funnel<OFOxmActsetOutputVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmActsetOutputVer15 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x80005604L
            sink.putInt((int) 0x80005604);
            message.value.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmActsetOutputVer15> {
        @Override
        public void write(ByteBuf bb, OFOxmActsetOutputVer15 message) {
            // fixed value property typeLen = 0x80005604L
            bb.writeInt((int) 0x80005604);
            message.value.write4Bytes(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmActsetOutputVer15(");
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
        OFOxmActsetOutputVer15 other = (OFOxmActsetOutputVer15) obj;

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
