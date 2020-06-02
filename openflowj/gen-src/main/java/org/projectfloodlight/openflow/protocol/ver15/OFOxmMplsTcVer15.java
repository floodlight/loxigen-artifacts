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

class OFOxmMplsTcVer15 implements OFOxmMplsTc {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmMplsTcVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int LENGTH = 5;

        private final static U8 DEFAULT_VALUE = U8.ZERO;

    // OF message fields
    private final U8 value;
//
    // Immutable default instance
    final static OFOxmMplsTcVer15 DEFAULT = new OFOxmMplsTcVer15(
        DEFAULT_VALUE
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmMplsTcVer15(U8 value) {
        if(value == null) {
            throw new NullPointerException("OFOxmMplsTcVer15: property value cannot be null");
        }
        this.value = value;
    }

    // Accessors for OF message fields
    @Override
    public long getTypeLen() {
        return 0x80004601L;
    }

    @Override
    public U8 getValue() {
        return value;
    }

    public OFOxm<U8> getCanonical() {
        // exact match OXM is always canonical
        return this;
    }

    @Override
    public U8 getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.5");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<U8> getMatchField() {
        return MatchField.MPLS_TC;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFOxmMplsTc.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmMplsTc.Builder {
        final OFOxmMplsTcVer15 parentMessage;

        // OF message fields
        private boolean valueSet;
        private U8 value;

        BuilderWithParent(OFOxmMplsTcVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getTypeLen() {
        return 0x80004601L;
    }

    @Override
    public U8 getValue() {
        return value;
    }

    @Override
    public OFOxmMplsTc.Builder setValue(U8 value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<U8> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.5");
    }

    @Override
    public U8 getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.5");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<U8> getMatchField() {
        return MatchField.MPLS_TC;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFOxmMplsTc build() {
                U8 value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");

                //
                return new OFOxmMplsTcVer15(
                    value
                );
        }

    }

    static class Builder implements OFOxmMplsTc.Builder {
        // OF message fields
        private boolean valueSet;
        private U8 value;

    @Override
    public long getTypeLen() {
        return 0x80004601L;
    }

    @Override
    public U8 getValue() {
        return value;
    }

    @Override
    public OFOxmMplsTc.Builder setValue(U8 value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<U8> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.5");
    }

    @Override
    public U8 getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.5");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<U8> getMatchField() {
        return MatchField.MPLS_TC;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFOxmMplsTc build() {
            U8 value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");


            return new OFOxmMplsTcVer15(
                    value
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmMplsTc> {
        @Override
        public OFOxmMplsTc readFrom(ByteBuf bb) throws OFParseError {
            // fixed value property typeLen == 0x80004601L
            int typeLen = bb.readInt();
            if(typeLen != (int) 0x80004601)
                throw new OFParseError("Wrong typeLen: Expected=0x80004601L(0x80004601L), got="+typeLen);
            U8 value = U8.of(bb.readByte());

            OFOxmMplsTcVer15 oxmMplsTcVer15 = new OFOxmMplsTcVer15(
                    value
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmMplsTcVer15);
            return oxmMplsTcVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmMplsTcVer15Funnel FUNNEL = new OFOxmMplsTcVer15Funnel();
    static class OFOxmMplsTcVer15Funnel implements Funnel<OFOxmMplsTcVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmMplsTcVer15 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x80004601L
            sink.putInt((int) 0x80004601);
            message.value.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmMplsTcVer15> {
        @Override
        public void write(ByteBuf bb, OFOxmMplsTcVer15 message) {
            // fixed value property typeLen = 0x80004601L
            bb.writeInt((int) 0x80004601);
            bb.writeByte(message.value.getRaw());


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmMplsTcVer15(");
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
        OFOxmMplsTcVer15 other = (OFOxmMplsTcVer15) obj;

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
