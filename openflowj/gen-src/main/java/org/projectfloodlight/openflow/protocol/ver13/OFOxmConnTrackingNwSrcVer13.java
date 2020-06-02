// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver13;

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

class OFOxmConnTrackingNwSrcVer13 implements OFOxmConnTrackingNwSrc {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmConnTrackingNwSrcVer13.class);
    // version: 1.3
    final static byte WIRE_VERSION = 4;
    final static int LENGTH = 8;

        private final static U32 DEFAULT_VALUE = U32.ZERO;

    // OF message fields
    private final U32 value;
//
    // Immutable default instance
    final static OFOxmConnTrackingNwSrcVer13 DEFAULT = new OFOxmConnTrackingNwSrcVer13(
        DEFAULT_VALUE
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmConnTrackingNwSrcVer13(U32 value) {
        if(value == null) {
            throw new NullPointerException("OFOxmConnTrackingNwSrcVer13: property value cannot be null");
        }
        this.value = value;
    }

    // Accessors for OF message fields
    @Override
    public long getTypeLen() {
        return 0x1f004L;
    }

    @Override
    public U32 getValue() {
        return value;
    }

    public OFOxm<U32> getCanonical() {
        // exact match OXM is always canonical
        return this;
    }

    @Override
    public U32 getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.3");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<U32> getMatchField() {
        return MatchField.CONN_TRACKING_NW_SRC;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



    public OFOxmConnTrackingNwSrc.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmConnTrackingNwSrc.Builder {
        final OFOxmConnTrackingNwSrcVer13 parentMessage;

        // OF message fields
        private boolean valueSet;
        private U32 value;

        BuilderWithParent(OFOxmConnTrackingNwSrcVer13 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getTypeLen() {
        return 0x1f004L;
    }

    @Override
    public U32 getValue() {
        return value;
    }

    @Override
    public OFOxmConnTrackingNwSrc.Builder setValue(U32 value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<U32> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.3");
    }

    @Override
    public U32 getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.3");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<U32> getMatchField() {
        return MatchField.CONN_TRACKING_NW_SRC;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



        @Override
        public OFOxmConnTrackingNwSrc build() {
                U32 value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");

                //
                return new OFOxmConnTrackingNwSrcVer13(
                    value
                );
        }

    }

    static class Builder implements OFOxmConnTrackingNwSrc.Builder {
        // OF message fields
        private boolean valueSet;
        private U32 value;

    @Override
    public long getTypeLen() {
        return 0x1f004L;
    }

    @Override
    public U32 getValue() {
        return value;
    }

    @Override
    public OFOxmConnTrackingNwSrc.Builder setValue(U32 value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<U32> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.3");
    }

    @Override
    public U32 getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.3");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<U32> getMatchField() {
        return MatchField.CONN_TRACKING_NW_SRC;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

//
        @Override
        public OFOxmConnTrackingNwSrc build() {
            U32 value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");


            return new OFOxmConnTrackingNwSrcVer13(
                    value
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmConnTrackingNwSrc> {
        @Override
        public OFOxmConnTrackingNwSrc readFrom(ByteBuf bb) throws OFParseError {
            // fixed value property typeLen == 0x1f004L
            int typeLen = bb.readInt();
            if(typeLen != 0x1f004)
                throw new OFParseError("Wrong typeLen: Expected=0x1f004L(0x1f004L), got="+typeLen);
            U32 value = U32.of(bb.readInt());

            OFOxmConnTrackingNwSrcVer13 oxmConnTrackingNwSrcVer13 = new OFOxmConnTrackingNwSrcVer13(
                    value
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmConnTrackingNwSrcVer13);
            return oxmConnTrackingNwSrcVer13;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmConnTrackingNwSrcVer13Funnel FUNNEL = new OFOxmConnTrackingNwSrcVer13Funnel();
    static class OFOxmConnTrackingNwSrcVer13Funnel implements Funnel<OFOxmConnTrackingNwSrcVer13> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmConnTrackingNwSrcVer13 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x1f004L
            sink.putInt(0x1f004);
            message.value.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmConnTrackingNwSrcVer13> {
        @Override
        public void write(ByteBuf bb, OFOxmConnTrackingNwSrcVer13 message) {
            // fixed value property typeLen = 0x1f004L
            bb.writeInt(0x1f004);
            bb.writeInt(message.value.getRaw());


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmConnTrackingNwSrcVer13(");
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
        OFOxmConnTrackingNwSrcVer13 other = (OFOxmConnTrackingNwSrcVer13) obj;

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
